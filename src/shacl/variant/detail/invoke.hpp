struct invoke_fn {
  template<typename F, typename... Args>
  constexpr auto operator(F, Args...) const ->
  boost::hana::type
  <trait::InvokeResult_t
   <typename F::type, typename Args::type...>>{
    return {};
  }
};

static constexpr invoke_fn invoke{};
