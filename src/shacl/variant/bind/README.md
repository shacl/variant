### bind

`shacl::variant::map` can be thought of as a generalization of
`shacl::variant::visit` and as an implementation of the functor pattern on the
`shacl::Variant`. In contrast,  `shacl::variant::bind` can be thought of as a
special case of `shacl::variant::map` and as an implementation of the monad
pattern for `shacl::Variant`.

----------------------------

#### Example:

Consider a pair of an overloaded functions objects, `classify` and `print`,
and support types `Small` and `Large`.

```cpp
// support.hpp

#include "shacl/variant.hpp"
#include <iostream>

template<typename T>
struct Small {
  T value;
};

template<typename T>
struct Large {
  T value;
};

struct classify_fn {
  template<typename T>
  auto operator()(T value) const
  -> shacl::Variant<Small<T>, Large<T>> {
    if (value < 10) {
      return Small<T>{value};
    } else {
      return Large<T>{value};
    }
  }
};

static constexpr classify_fn classify{};

struct print_fn {
  template<typename T>
  void operator()(Small<T> small) const {
    std::cout << "Encountered a small value: " << small.value << std::end;;
  }

  template<typename T>
  void operator()(Large<T> large) const {
    std::cout << "Encountered a large value: " << large.value << std::end;;
  }
};

static constexpr print_fn print{};

```

Suppose that, based on some runtime parameter, our program is required to deal
in either integer or floating point data. One means to support this dispatch is
by way of a variant.

```cpp
#include "support.hpp"
#include <exception>
#include <string>

int main(){
  auto vid = []() -> shacl::Variant<int, double> {
    std::string dispatch;
    std::cin >> dispatch;

    if (dispatch == "int"){
      int sink;
      std::cin >> sink;
      return sink;
    } else if (dispatch == "double"){
      double sink;
      std::cin >> double;
      return sink;
    }
    throw std::runtime_error("unrecognized dispatch argument");
  }();

 // ...
}

```

How might we classify the value read into the `vid` variable? Consider the
return type of an application of `shacl::map` in conjunction with an instance of
tha `classify` callable.

```cpp
using shacl::Variant;
Variant<Variant<Small<int>, Large<int>>
        Variant<Small<double>, Large<double>>> result;

result = shacl::variant::map(classify, vid);
```

We observe a nesting of the `Variant` template. This can complicate the
consumption of a result downstream under some circumstances. Consider how we
might apply an instance of the `print` callable defined previously.

```cpp
shacl::visit(shacl::visit(print), result);
```

While this certainly works, composition was a bit more complicated (and
potentially a bit less efficient) than is otherwise possible. In this case, the
 nesting of `Variant` instantiations does not serve our interests. It would be
preferable to 'flatten' the `Variant` nesting such that only a single level of
visitation is necessary.

This is the role `bind` fills. `bind` accepts as arguments, a callable which
returns a `Variant` based on an argument type and one or more `Variant`
arguments. The return type of this operation is a variant collecting the
all the possible alternatives of the callables possible variant return types.
Applying bind to our example using `classify` and `vid`.

```cpp
using shacl::Variant;
Variant<Small<int>, Large<int>, Small<double>, Large<double>> result;

result = shacl::variant::bind(classify, vid);
shacl::visit(print, result);
```

Applying this to our example program yields the following:

```cpp
#include "support.hpp"
#include <exception>
#include <string>

int main(){
  auto vid = []() -> shacl::Variant<int, double> {
    std::string dispatch;
    std::cin >> dispatch;

    if (dispatch == "int"){
      int sink;
      std::cin >> sink;
      return sink;
    } else if (dispatch == "double"){
      double sink;
      std::cin >> sink;
      return sink;
    }
    throw std::runtime_error("unrecognized dispatch argument");
  }();


  shacl::variant::visit(print, shacl::variant::bind(classify, vid));
}
```

-----------------------------

Like `visit` and `map`, `bind` supports a form of partial evaluation to 'lift' a
callable to apply to `Variant` arguments.

----------------------------

#### Example:

Again, this is convenient in the context of collections of variants. Suppose
that in our simple program above, rather than classify a single value,
classified a user-specified number of values.

```cpp
#include "support.hpp"

#include <boost/hana/functional/compose.hpp>

#include <algorithm>
#include <exception>
#include <string>
#include <vector>

int main(){
  int count;
  std::cin >> count;

  auto read = []() -> shacl::Variant<int, double> {
    std::string dispatch;
    std::cin >> dispatch;

    if (dispatch == "int"){
      int sink;
      std::cin >> sink;
      return sink;
    } else if (dispatch == "double"){
      double sink;
      std::cin >> sink;
      return sink;
    }
    throw std::runtime_error("unrecognized dispatch argument");
  };

  std::vector<shacl::Variant<int, double>> vvid;
  while(count--){ vvid.push_back(read()); }

  auto lifted_print = shacl::variant::visit(print);
  auto lifted_classify = shacl::variant::bind(classify);
  auto composition = boost::hana::compose(lifted_print, lifted_classify);

  std::for_each(vvid.begin(), vvid.end(), composition);
}
```

-----------------------------
