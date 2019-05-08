#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("sum"){
  using boost::hana::type;
  using boost::hana::type_c;

  GIVEN("two mutally exclusive variants"){
    constexpr auto a = type_c<shacl::Variant<int, double>>;
    constexpr auto b = type_c<shacl::Variant<int*, double*>>;

    THEN("the sum of the two types will be the union of the parameters"){
      constexpr auto reference = boost::hana::make_set(type_c<int>,
                                                       type_c<double>,
                                                       type_c<int*>,
                                                       type_c<double*>);

      constexpr auto trial = shacl::variant::detail::alternatives_of
                             (shacl::variant::detail::sum(a, b));

      REQUIRE((reference == trial).value);
    }
  }

  GIVEN("two partially overlapping variants"){
    constexpr auto a = type_c<shacl::Variant<int, double, char>>;
    constexpr auto b = type_c<shacl::Variant<int*, double*, char>>;

    THEN("the sum of the two types will be the union of the parameters"){
      constexpr auto reference = boost::hana::make_set(type_c<char>,
                                                       type_c<int>,
                                                       type_c<double>,
                                                       type_c<int*>,
                                                       type_c<double*>);

      constexpr auto trial = shacl::variant::detail::alternatives_of
                             (shacl::variant::detail::sum(a, b));

      REQUIRE((reference == trial).value);
    }
  }

  GIVEN("two totally overlapping variants"){
    constexpr auto a = type_c<shacl::Variant<int, double, char>>;

    THEN("the sum of the two types will be the union of the parameters"){
      constexpr auto reference = boost::hana::make_set(type_c<char>,
                                                       type_c<int>,
                                                       type_c<double>);

      constexpr auto trial = shacl::variant::detail::alternatives_of
                             (shacl::variant::detail::sum(a, a));

      REQUIRE((reference == trial).value);
    }
  }
}
