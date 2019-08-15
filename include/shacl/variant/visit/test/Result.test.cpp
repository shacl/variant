#include "catch2/catch.hpp"
#include "shacl/variant.hpp"
#include "callable.hpp"

SCENARIO("expanding the Result type calculation"){
  auto result_of_callable =
    boost::hana::partial
    (shacl::variant::detail::invoke, boost::hana::type_c<callable_fn>);

  auto result_of_unpacking_tuple_into_callable =
    boost::hana::reverse_partial
    (boost::hana::unpack, result_of_callable);

  // a tuple of tuples of type values
  auto argument_combinations =
    boost::hana::cartesian_product
    (boost::hana::make_tuple
     (shacl::variant::detail::arguments_of
      (boost::hana::type_c<shacl::Variant<int, double>>)));

  REQUIRE((boost::hana::to_set(argument_combinations)
           == boost::hana::make_set
           (boost::hana::make_tuple(boost::hana::type_c<int&&>),
            boost::hana::make_tuple(boost::hana::type_c<double&&>))).value);

  auto results =
    boost::hana::transform(argument_combinations,
                           result_of_unpacking_tuple_into_callable);

  REQUIRE((results
           == boost::hana::make_tuple(boost::hana::type_c<int>,
                                      boost::hana::type_c<int>)).value);

  auto unique_results =
    boost::hana::to_tuple(boost::hana::to_set(results));

  REQUIRE((unique_results
           == boost::hana::make_tuple(boost::hana::type_c<int>)).value);

  REQUIRE((boost::hana::size(unique_results) == boost::hana::size_c<1>).value);
}
