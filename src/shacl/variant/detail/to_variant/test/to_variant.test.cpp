#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("to_variant"){
  using boost::hana::type;
  using boost::hana::type_c;

  GIVEN("A collection of types"){
    constexpr auto a = type_c<int>;
    constexpr auto b = type_c<int*>;
    constexpr auto c = type_c<double>;
    constexpr auto d = type_c<double*>;

    constexpr auto reference = boost::hana::make_set(a, b, c, d);

    WHEN("invoked with to_variant"){
      auto variant_type = shacl::variant::detail::to_variant(a, b, c, d, a);

      THEN("the variant alternatives will match the input set"){
        REQUIRE((reference ==
                 shacl::variant::detail::alternatives_of(variant_type)).value);
      }
    }
  }
}
