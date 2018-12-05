### map

`shacl::variant::map`, function template repesenting something of a
generalization of `shacl::variant::visit` and effectively providing a
functor interface (in the category theory sense) to `shacl::Variant`.

----------------------------

#### Example:

Consider a use case in which it is desirable that the return type of a callable
vary based on the type of its argument. Variant visitation is not (directly)
applicable in this case, as `std::visit` requires that the callable argument
return the same type for each of the variant argument parameter types.

```cpp
#include "shacl/variant.hpp"

#include <iostream>
#include <iterator>
#include <transform>
#include <vector>

struct to_vector {
  template<typename T>
  std::vector<T> operator()(T t) const { return {std::move(t)}; }
};

int main(){
  shacl::Variant<int, double> vvid = 10;

  shacl::Variant<std::vector<int>, std::vector<double>> vvivd =
    shacl::variant::map(to_vector, vvid);

  std::cout << shacl::variant::get<0>(vvivd).front() << std::endl;
}
```

The output of this program is:

```
10
```

For more information regarding this functor pattern, please see the *Related
Material* at the end of this README.

-----------------------

Just as `shacl::variant::visit` supports a form of partial evaluation which
effectively 'lifts' an argument callable to visit a variant argument, so too
does `shacl::variant::map`.

-----------------------

#### Example:

Under a circumstance in which a callable is to be mapped over a collection
rather than a single variant instance, the unary `map` overload provides a
mechanism to 'lift' a callable to map over argument variants.

```cpp
#include "shacl/variant.hpp"

#include <iostream>
#include <iterator>
#include <transform>
#include <vector>

struct to_vector {
  template<typename T>
  std::vector<T> operator()(T t) const { return {std::move(t)}; }
};

int main(){
  std::vector<shacl::Variant<int, double>> vvid;

  vvid.emplace_back(1);
  vvid.emplace_back(2.5);
  vvid.emplace_back(3);

  std::vector
  <shacl::Variant
   <std::vector<int>,
    std::vector<double>>> vvivd;

  auto lift = shacl::variant::map(to_vector);
  // lift is instance of a new class which visits and applies the callable
  // operator() to it's arguments returning a variant of possible callable
  // return types.

  std::transform(vvid.begin(), vvid.end(), std::back_inserter(vvivd), lift);

  auto print = shacl::variant::visit([](const auto& v){
     std::cout << v.front() << std::endl;
  });

  for(const auto& v : vs){ print(v); }
}
```

The output of this program is:

```
1
2.5
3
```

------------------------------

For more information regarding this functor pattern, please see the *Related
Material* at the end of this README.

### Related Material

+ [Using Types Effectively](https://www.youtube.com/watch?v=ojZbFIQSdl8)
+ [The (Functional) Functor Pattern in C++](https://www.fpcomplete.com/blog/2012/07/the-functor-pattern-in-c)
