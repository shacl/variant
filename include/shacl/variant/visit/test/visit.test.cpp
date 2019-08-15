#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"
#include "callable.hpp"
#include "f.hpp"

SCENARIO("visit"){
  GIVEN("calls preserve argument and callable value categories"){
    using boost::hana::size_c;
    constexpr auto indices =
      boost::hana::make_tuple(size_c<0>, size_c<1>, size_c<2>, size_c<3>,
                              size_c<4>, size_c<5>, size_c<6>, size_c<7>,
                              size_c<8>, size_c<9>, size_c<10>, size_c<11>,
                              size_c<12>, size_c<13>, size_c<14>, size_c<15>,
                              size_c<16>, size_c<17>, size_c<18>, size_c<19>,
                              size_c<20>, size_c<21>, size_c<22>, size_c<23>,
                              size_c<24>, size_c<25>, size_c<26>, size_c<27>,
                              size_c<28>, size_c<29>, size_c<30>, size_c<31>);
    boost::hana::for_each(indices, [](auto index){
        /*constexpr*/ bool correct = index.value == f(index);
        REQUIRE(correct);
      });
  }

  GIVEN("an overloaded callable"){
    callable_fn callable{};

    WHEN("lifted to visit upon a variant"){
      auto lifted_callable = shacl::variant::visit(callable);

      GIVEN("a variant over two types"){
        THEN("the function will be callable on variant types"){
          REQUIRE(8 == lifted_callable(shacl::Variant<int, double>{1}));
          REQUIRE(9 == lifted_callable(shacl::Variant<int, double>{1.0}));
          REQUIRE(24 ==
                  std::move(lifted_callable)(shacl::Variant<int, double>{1}));
          REQUIRE(25 ==
                  std::move(lifted_callable)(shacl::Variant<int, double>{1.0}));
        }
      }
    }
  }

  SECTION("SFINAE-friendliness"){
    GIVEN("valid arguments"){
      THEN("InvokeDefined returns true"){
        REQUIRE(shacl::trait::InvokeDefined_v
                <shacl::variant::visit_fn,
                 callable_fn,
                 shacl::Variant<int, double>>);
      }
    }

    GIVEN("invalid arguments"){
      THEN("InvokeDefined returns false"){
        REQUIRE_FALSE(shacl::trait::InvokeDefined_v
                      <shacl::variant::visit_fn,
                      callable_fn,
                      shacl::Variant<int, double, int*>>);
      }
    }
  }
}
