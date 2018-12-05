#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/variant.hpp"

SCENARIO("cast"){
  GIVEN("an instance of a variant type"){
    shacl::Variant<int, double*> vid = 1;

    THEN("the variant can be widened"){
      auto vidip = shacl::variant::cast<int, double*, int*>(vid);
      REQUIRE(0 == vidip.index());
    }

    THEN("alternatives can be rearranged"){
      auto vdpi = shacl::variant::cast<double*, int>(vid);
      REQUIRE(1 == vdpi.index());
    }

    THEN("alternatives can be narrowed"){
      WHEN("the stored value is a member of the constrained set "){
        auto vi = shacl::variant::cast<int>(vid);
        REQUIRE(0 == vi.index());
        REQUIRE(1 == shacl::variant::get<0>(vi));
      }

      WHEN("a member of the constrained set is constructible from the stored value"){
        auto vd = shacl::variant::cast<double>(vid);
        REQUIRE(0 == vd.index());
        REQUIRE(1.0 == shacl::variant::get<0>(vd));
      }

      WHEN("no member of the constrained set is constructible the stored value"){
        REQUIRE_THROWS(shacl::variant::cast<double*>(vid));
      }
    }
  }
}
