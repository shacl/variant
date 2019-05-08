template<typename Result>
struct construct_fn {
  template<typename Arg,
           std::enable_if_t
           <std::is_constructible<Result, Arg>::value, bool> = true>
  constexpr Result operator()(Arg&& arg) const
    noexcept(std::is_nothrow_constructible<Result, Arg>::value) {
    return {std::forward<Arg>(arg)};
  }
};

template<typename Result>
static constexpr construct_fn<Result> construct{};
