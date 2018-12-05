struct is_constructible_fn {
  template<typename Result, typename... Args>
  constexpr boost::hana::bool_
  <std::is_constructible<typename Result::type, typename Args::type...>::value>
  operator()(Result, Args...) const { return {}; }
};

static constexpr is_constructible_fn is_constructible{};
