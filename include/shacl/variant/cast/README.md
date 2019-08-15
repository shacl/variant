### variant::cast

`shacl::variant::cast` provides a mechanism to 'widen' or 'narrow' a variant.

--------------------------

#### Example (Widening):

Consider a use case in which a function argument is required to be of a
particular variant type, which is a superset of alternatives of a variant
instance on hand.

```cpp
#include "shacl/variant.hpp"

#include <iostream>
#include <string>

void print(const shacl::Variant<int, double, std::string>& vids) {
  shacl::variant::visit([](auto&& v){ std::cout << v << std::endl; }, vids);
}

int main(){
  shacl::Variant<int, double> vid = 1.5;
  print(shacl::variant::cast<int, double, std::string>(vid));
}
```

The output of this program is:

```
1.5
```

#### Example (Narrowing):

Consider a use case where, like the previous example, a function argument is
required to be of a particular variant type. However, in this case, assume
the argument variant supports only a subset of the alternatives of the variant
instance on hand.

```cpp
#include "shacl/variant.hpp"

#include <iostream>
#include <string>

void print(const shacl::Variant<int, double>& vid) {
  shacl::variant::visit
  ([](auto&& v){ std::cout << v << '\n' << std::endl; }, vids);
}

int main(){
  shacl::Variant<int, double, std::string> vids;

  vids = 1.5;
  print(shacl::variant::cast<int, double>(vids));

  vids = "string";
  try {
    print(shacl::variant::cast<int, double>(vids));
  } catch (shacl::variant::bad_cast& bc) {
    std::cout << "Failed at runtime\n" << std::endl;
  }

  if (not shacl::trait::InvokeDefined_v
          <shacl::variant::cast_fn<int, double>,
           shacl::Variant<int*, double*>>){
    std::cout << "Impossible casts are SFINAE'd out" << std::endl;
  }
}
```

The output of this program is:

```
1.5

Failed at runtime

Impossible casts are SFINAE'd out
```

----------------------------
