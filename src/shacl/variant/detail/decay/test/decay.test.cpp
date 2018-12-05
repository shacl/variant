#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("decay"){
  using boost::hana::type_c;

  WHEN("unqualified"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<int>);
    REQUIRE(equal);
  }

  WHEN("lvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<int&>);
    REQUIRE(equal);
  }

  WHEN("rvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<int&&>);
    REQUIRE(equal);
  }

  WHEN("const"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const int>);
    REQUIRE(equal);
  }

  WHEN("const lvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const int&>);
    REQUIRE(equal);
  }

  WHEN("const rvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const int&&>);
    REQUIRE(equal);
  }

  WHEN("volatile"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<volatile int>);
    REQUIRE(equal);
  }

  WHEN("volatile lvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<volatile int&>);
    REQUIRE(equal);
  }

  WHEN("volatile rvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<volatile int&&>);
    REQUIRE(equal);
  }

  WHEN("const volatile"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const volatile int>);
    REQUIRE(equal);
  }

  WHEN("const volatile lvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const volatile int&>);
    REQUIRE(equal);
  }

  WHEN("const volatile rvalue reference"){
    constexpr bool equal =
      type_c<int> == shacl::variant::detail::decay(type_c<const volatile int&&>);
    REQUIRE(equal);
  }
}
