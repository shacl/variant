#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("argument_type_product"){
  GIVEN("two variant types with two combinations each"){
    using namespace boost::hana;

    auto typeA = type_c<shacl::Variant<int, double>>;
    auto typeB = type_c<shacl::Variant<int*, double*>>;

    THEN("then there is a cartesian product of the variant argument types."
         " These are 4 combinations of arguments that a callable may recieve"
         " (and therefore must support) during visitation"){

      auto product =
        shacl::variant::detail::argument_type_product(typeA, typeB);

      REQUIRE(length(product).value == 4);
      REQUIRE((make_tuple(type_c<int&&>, type_c<int*&&>) ^in^ product).value);
      REQUIRE((make_tuple(type_c<int&&>, type_c<double*&&>) ^in^ product).value);
      REQUIRE((make_tuple(type_c<double&&>, type_c<int*&&>) ^in^ product).value);
      REQUIRE((make_tuple(type_c<double&&>, type_c<double*&&>) ^in^ product).value);
    }

    SECTION("sfinae-friendliness"){
      auto overloadSet = [](auto&&... args)
        -> decltype(shacl::variant::detail::argument_type_product(args...)){
        return shacl::variant::detail::argument_type_product(args...);
      };

      using argument_type_product_fn = decltype(overloadSet);

      REQUIRE(shacl::trait::InvokeDefined_v
              <argument_type_product_fn, decltype(typeA), decltype(typeB)>);

      REQUIRE_FALSE(
        shacl::trait::InvokeDefined_v
        <argument_type_product_fn, decltype(typeA), type<int>>);
    }
  }
}
