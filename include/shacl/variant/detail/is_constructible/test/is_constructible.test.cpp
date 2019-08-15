#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("construct"){
  using boost::hana::type;
  using boost::hana::type_c;

  GIVEN("an invalid argument for construction"){
    THEN("is_constructible returns false"){
      REQUIRE_FALSE(
        shacl::variant::detail::is_constructible
        (type_c<double>, type_c<double*>).value);
    }
  }

  GIVEN("an valid argument for construction"){
    THEN("is_constructible returns true"){
      REQUIRE(
        shacl::variant::detail::is_constructible
        (type_c<double>, type_c<int>).value);
    }
  }
}
