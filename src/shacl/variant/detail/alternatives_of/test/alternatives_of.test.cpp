#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("alternatives_of"){
  using boost::hana::type_c;

  constexpr auto reference =
      boost::hana::make_set(type_c<int>, type_c<double>);

  GIVEN("a variant instantiation with unique parameters"){
    using variant = shacl::Variant<int, double>;

    GIVEN("an type-value of the variant instantiation"){
      constexpr boost::hana::type<variant> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the variant instantiation"){
      constexpr boost::hana::type<variant&> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the const lvalue reference variant instantiation"){
      constexpr boost::hana::type<const variant&> value{};

      THEN("alternatives_of returns a set of value types"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the rvalue variant reference instantiation"){
      constexpr boost::hana::type<variant&&> value{};

      THEN("alternatives_of returns a set of value types"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }
  }

  GIVEN("a variant instantiation with repeated parameters"){
    using variant = shacl::Variant<int, double, int>;

    GIVEN("an type-value of the variant instantiation"){
      constexpr boost::hana::type<variant> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the lvalue reference variant instantiation"){
      constexpr boost::hana::type<variant&> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the const lvalue reference variant instantiation"){
      constexpr boost::hana::type<const variant&> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the rvalue variant reference instantiation"){
      constexpr boost::hana::type<variant&&> value{};

      THEN("alternatives_of returns a set of value type"){
        constexpr auto trial = shacl::variant::detail::alternatives_of(value);
        REQUIRE(reference == trial);
      }
    }
  }
}
