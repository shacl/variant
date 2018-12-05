#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("arguments_of"){
  using boost::hana::type_c;

  GIVEN("a variant instantiation with unique parameters"){
    using variant = shacl::Variant<int, double>;

    GIVEN("an type-value of the variant instantiation"){
      boost::hana::type<variant> value;

      THEN("arguments_of returns a tuple of rvalue type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&&>, type_c<double&&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the lvalue reference variant instantiation"){
      boost::hana::type<variant&> value;

      THEN("arguments_of returns a tuple of lvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&>, type_c<double&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the const lvalue reference variant instantiation"){
      boost::hana::type<const variant&> value;

      THEN("arguments_of returns a tuple of const lvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<const int&>, type_c<const double&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the rvalue variant reference instantiation"){
      boost::hana::type<variant&&> value;

      THEN("arguments_of returns a tuple of rvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&&>, type_c<double&&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }
  }

  GIVEN("a variant instantiation with repeated parameters"){
    using variant = shacl::Variant<int, double, int>;

    GIVEN("an type-value of the variant instantiation"){
      boost::hana::type<variant> value;

      THEN("arguments_of returns a tuple of rvalue type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&&>, type_c<double&&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the lvalue reference variant instantiation"){
      boost::hana::type<variant&> value;

      THEN("arguments_of returns a tuple of lvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&>, type_c<double&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the const lvalue reference variant instantiation"){
      boost::hana::type<const variant&> value;

      THEN("arguments_of returns a tuple of const lvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<const int&>, type_c<const double&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }

    GIVEN("an type-value of the rvalue variant reference instantiation"){
      boost::hana::type<variant&&> value;

      THEN("arguments_of returns a tuple of rvalue reference type values"){
        constexpr auto reference =
          boost::hana::make_tuple(type_c<int&&>, type_c<double&&>);

        constexpr auto trial = shacl::variant::detail::arguments_of(value);
        REQUIRE(reference == trial);
      }
    }
  }
}
