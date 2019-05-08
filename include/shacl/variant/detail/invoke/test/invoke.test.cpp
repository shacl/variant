#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

struct argument {};

template<int>
struct result {};

struct callable {
  result<0> operator()  (argument&) &;
  result<1> operator()  (const argument&) &;
  result<2> operator()  (argument&) const &;
  result<3> operator()  (const argument&) const &;
  result<4> operator()  (argument&&) &;
  result<5> operator()  (const argument&&) &;
  result<6> operator()  (argument&&) const &;
  result<7> operator()  (const argument&&) const &;
  result<8> operator()  (argument&) &&;
  result<9> operator()  (const argument&) &&;
  result<10> operator() (argument&) const &&;
  result<11> operator() (const argument&) const &&;
  result<12> operator() (argument&&) &&;
  result<13> operator() (const argument&&) &&;
  result<14> operator() (argument&&) const &&;
  result<15> operator() (const argument&&) const &&;
};

SCENARIO("invoke"){
  using boost::hana::type;
  using boost::hana::type_c;

  GIVEN("an SFINAE-friendly undefined invocation"){
    REQUIRE_FALSE(shacl::trait::InvokeDefined_v<callable, int>);

    THEN("invoke function "){
    REQUIRE_FALSE(shacl::trait::InvokeDefined_v
                  <shacl::variant::detail::invoke_fn,
                   type<callable>, type<int>>);
    }
  }

  GIVEN("a well-defined invocation"){
    THEN("invoke will respect argument and callable value categories"){
      REQUIRE((type_c<result<0>>
               == shacl::variant::detail::invoke(type_c<callable&>,
                                                 type_c<argument&>)).value);
      REQUIRE((type_c<result<1>>
               == shacl::variant::detail::invoke(type_c<callable&>,
                                                 type_c<const argument&>)).value);
      REQUIRE((type_c<result<2>>
               == shacl::variant::detail::invoke(type_c<const callable&>,
                                                 type_c<argument&>)).value);
      REQUIRE((type_c<result<3>>
               == shacl::variant::detail::invoke(type_c<const callable&>,
                                                 type_c<const argument&>)).value);
      REQUIRE((type_c<result<4>>
               == shacl::variant::detail::invoke(type_c<callable&>,
                                                 type_c<argument&&>)).value);
      REQUIRE((type_c<result<5>>
               == shacl::variant::detail::invoke(type_c<callable&>,
                                                 type_c<const argument&&>)).value);
      REQUIRE((type_c<result<6>>
               == shacl::variant::detail::invoke(type_c<const callable&>,
                                                 type_c<argument&&>)).value);
      REQUIRE((type_c<result<7>>
               == shacl::variant::detail::invoke(type_c<const callable&>,
                                                 type_c<const argument&&>)).value);
      REQUIRE((type_c<result<8>>
               == shacl::variant::detail::invoke(type_c<callable&&>,
                                                 type_c<argument&>)).value);
      REQUIRE((type_c<result<9>>
               == shacl::variant::detail::invoke(type_c<callable&&>,
                                                 type_c<const argument&>)).value);
      REQUIRE((type_c<result<10>>
               == shacl::variant::detail::invoke(type_c<const callable&&>,
                                                 type_c<argument&>)).value);
      REQUIRE((type_c<result<11>>
               == shacl::variant::detail::invoke(type_c<const callable&&>,
                                                 type_c<const argument&>)).value);
      REQUIRE((type_c<result<12>>
               == shacl::variant::detail::invoke(type_c<callable&&>,
                                                 type_c<argument&&>)).value);
      REQUIRE((type_c<result<13>>
               == shacl::variant::detail::invoke(type_c<callable&&>,
                                                 type_c<const argument&&>)).value);
      REQUIRE((type_c<result<14>>
               == shacl::variant::detail::invoke(type_c<const callable&&>,
                                                 type_c<argument&&>)).value);
      REQUIRE((type_c<result<15>>
               == shacl::variant::detail::invoke(type_c<const callable&&>,
                                                 type_c<const argument&&>)).value);
    }
  }
}
