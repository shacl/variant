#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"
#include "callable.hpp"
#include "f.hpp"

SCENARIO("bind"){
  auto unwrap = shacl::variant::visit([](auto s){ return s.value; });

  GIVEN("an overloaded callable"){
    callable_fn callable{};

    WHEN("lifted to visit upon a variant"){
      auto lifted_callable = shacl::variant::bind(callable);

      GIVEN("a variant over two types"){
        THEN("the function will be callable on variant types"){
          REQUIRE(8 ==
                  unwrap(lifted_callable(shacl::Variant<int, double>{1})));
          REQUIRE(9 ==
                  unwrap(lifted_callable(shacl::Variant<int, double>{1.0})));
          REQUIRE(24 ==
                  unwrap
                  (std::move(lifted_callable)(shacl::Variant<int, double>{1})));
          REQUIRE(25 ==
                  unwrap
                  (std::move(lifted_callable)
                   (shacl::Variant<int, double>{1.0})));
        }
      }
    }
  }

  SECTION("calls preserve argument and callable value categories"){
    using boost::hana::int_c;
    constexpr auto indices =
      boost::hana::make_tuple
       // lvalue overloads
      (int_c<0>, int_c<1>, int_c<2>, int_c<3>,
       int_c<4>, int_c<5>, int_c<6>, int_c<7>,
       int_c<8>, int_c<9>, int_c<10>, int_c<11>,
       int_c<12>, int_c<13>, int_c<14>, int_c<15>,
       // rvalue overloads
       int_c<16>, int_c<17>, int_c<18>, int_c<19>,
       int_c<20>, int_c<21>, int_c<22>, int_c<23>,
       int_c<24>, int_c<25>, int_c<26>, int_c<27>,
       int_c<28>, int_c<29>, int_c<30>, int_c<31>);
    boost::hana::for_each(indices, [unwrap](auto index){
        /*constexpr*/ bool correct = index.value == unwrap(f(index));
        REQUIRE(correct);
      });
  }
}
