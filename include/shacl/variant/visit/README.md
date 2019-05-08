### variant::visit

`shacl::variant::visit` supports partial evaluation, allowing users to 'lift' a
 callable object to apply to variant instantiations.

---------------

#### Example:

Consider a use case in which, rather than visiting a callable upon a single
variant, we're interested in visiting a callable upon a collection of variant
objects.

```cpp
#include "shacl/variant.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <transform>
#include <vector>

struct callable {
  std::string operator()(int) const { return "int"; }
  std::string operator()(double) const { return "double"; }
};

int main(){
  std::vector<shacl::Variant<int, double>> vvid;

  vvid.emplace_back(1);
  vvid.emplace_back(2.0);
  vvid.emplace_back(3);

  std::vector<std::string> vs;

  auto lift = shacl::variant::visit(callable{});
  // lift is instance of a new class which visits and applies the callable
  // operator() to it's arguments

  std::transform(vvid.begin(), vvid.end(), std::back_inserter(vs), lift);
  for(const auto& s : vs){ std::cout << s << std::endl; }
}
```

The output of this program is:

```
int
double
int
```

---------------------------

In addition, both the unary and variadic forms of `shacl::variant::visit` are
SFINAE-friendly, so long as the argument callable is SFINAE-friendly. This
allows for visitation in type traits and for function constraints.

------------------------------

#### Example

```cpp
#include "shacl/variant.hpp"
#include "shacl/trait.hpp"

#include <iostream>
#include <string>

struct demo_fn {
  void operator()(int);
  void operator()(double);
};

int main(){
  {
    constexpr auto is_callable =
      shacl::trait::InvokeDefined_v
      <shacl::variant::visit_fn, demo_fn, shacl::Variant<int, double>>

    if (is_callable){
      std::cout << "visitation on variant<int, double>"
                   " with demo_fn is defined" << std::endl;
    } else {
      std::cout << "visitation on variant<int, double>"
                   " with demo_fn is not defined" << std::endl;
    }
  } {
    constexpr auto is_callable =
      shacl::trait::InvokeDefined_v
      <shacl::variant::visit_fn, demo_fn, shacl::Variant<int*, double*>>

    if (is_callable){
      std::cout << "visitation on variant<int*, double*>"
                   " with demo_fn is defined" << std::endl;
    } else {
      std::cout << "visitation on variant<int*, double*>"
                   " with demo_fn is not defined" << std::endl;
    }
  }

  auto lifted_demo = shacl::variant::visit(demo_fn{});
  using lifted_demo_fn = decltype(lifted_demo);

  {
    constexpr auto is_callable =
      shacl::trait::InvokeDefined_v
      <lifted_demo_fn, shacl::Variant<int, double>>

    if (is_callable){
      std::cout << "invocation of lifted_demo_fn on"
                   " variant<int, double> is defined" << std::endl;
    } else {
      std::cout << "invocation of lifted_demo_fn on"
                   " variant<int, double> is not defined" << std::endl;
    }
  } {
    constexpr auto is_callable =
      shacl::trait::InvokeDefined_v
      <lifted_demo_fn, shacl::Variant<int*, double*>>

    if (is_callable){
      std::cout << "invocation of lifted_demo_fn on"
                   " variant<int*, double*> is defined" << std::endl;
    } else {
      std::cout << "invocation of lifted_demo_fn on"
                   " variant<int*, double*> is not defined" << std::endl;
    }
  }
}
```

The output of this program is:

```
visitation on variant<int, double> with demo_fn is defined
visitation on variant<int*, double*> with demo_fn is not defined
invocation of lifted_demo_fn on variant<int*, double*> is defined
invocation of lifted_demo_fn on variant<int*, double*> is not defined
```

------------------------------
