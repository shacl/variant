#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("possible_result_types_of"){
  GIVEN("two variant types with two combinations each"){
    using namespace boost::hana;

    auto typeA = type_c<shacl::Variant<int, double>>;
    auto typeB = type_c<shacl::Variant<int*, double*>>;

    THEN("then a callable will need to support each combination of"
         " the cartesian product of the variant parameter types."){

      auto callable = type_c<decltype(make_tuple)>;
      auto results =
        shacl::variant::detail::possible_result_types_of
        (callable, typeA, typeB);

      REQUIRE(length(results).value == 4);
      REQUIRE((type_c<tuple<int, int*>> ^in^ results).value);
      REQUIRE((type_c<tuple<int, double*>> ^in^ results).value);
      REQUIRE((type_c<tuple<double, int*>>^in^ results).value);
      REQUIRE((type_c<tuple<double, double*>> ^in^ results).value);
    }

    SECTION("sfinae-friendliness"){
      auto overloadSet = [](auto&&... args)
        -> decltype(shacl::variant::detail::possible_result_types_of(args...)){
        return shacl::variant::detail::possible_result_types_of(args...);
      };

      using possible_result_types_of_fn = decltype(overloadSet);

      struct callable {
        boost::hana::size_t<0> operator()(int) const { return {}; }
        boost::hana::size_t<1> operator()(double) const { return {}; }
      };

      REQUIRE(shacl::trait::InvokeDefined_v
              <possible_result_types_of_fn, type<callable>, decltype(typeA)>);

      REQUIRE_FALSE(shacl::trait::InvokeDefined_v
              <possible_result_types_of_fn, type<callable>, decltype(typeB)>);
    }
  }
}
