template<typename Fn, typename... Args>
constexpr auto possible_result_types_of(Fn fn, Args... args)
  DECLTYPE_AUTO_RETURN(
    sfinae::transform
    (argument_type_product(args...),
     sfinae::reverse_partial
     (sfinae::unpack, sfinae::partial(invoke, fn))))
