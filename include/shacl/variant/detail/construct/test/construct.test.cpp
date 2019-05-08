#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("construct"){
  using boost::hana::type;
  using boost::hana::type_c;

  GIVEN("an invalid argument for construction"){
    THEN("then there will be an SFINAE-friendly failure"){
      REQUIRE_FALSE(shacl::trait::InvokeDefined_v
                    <shacl::variant::detail::construct_fn<double>, double*>);
    }
  }

  GIVEN("a valid construction argument"){
    double d = shacl::variant::detail::construct<double>(1.0);
    REQUIRE(d == 1.0);
  }
}
