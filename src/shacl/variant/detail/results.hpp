using namespace boost::hana;

#define RETURN_TYPE_OF(...) \
  decltype(__VA_ARGS__)     \
  { return (__VA_ARGS__); }

template<typename Fn, typename... Args>
constexpr auto results(Fn fn, Args... args)
  -> RETURN_TYPE_OF(
    transform
    (cartesian_product(make_tuple(arguments_of(args)...)),
     reverse_partial(unpack, partial(invoke, fn))))

#undef RETURN_TYPE_OF
