template<typename... Args>
constexpr auto argument_type_product(Args... args)
  DECLTYPE_AUTO_RETURN(
    boost::hana::cartesian_product
    (boost::hana::make_tuple(arguments_of(args)...)))
