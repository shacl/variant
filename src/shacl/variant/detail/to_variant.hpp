struct to_variant_fn {
  template<typename T, typename... Ts>
  constexpr auto operator()(T, Ts...) const
    -> boost::hana::type<Type<typename T::type, typename Ts::type...>> {
    return {};
  }
};

static constexpr to_variant_fn to_variant {};
