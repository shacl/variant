struct bind_fn {
  template<typename Fn, typename... Args>
  using Result =
    typename decltype
    (detail::sfinae::unpack
     (detail::possible_result_types_of
      (boost::hana::type_c<Fn>, boost::hana::type_c<Args>...),
      detail::sum))::type;

  template<typename Fn>
  using Curry = detail::Curry<Fn, bind_fn, Result>;

  template<typename Fn>
  static constexpr auto copyEfficient =
    boost::hana::bool_c
    <std::is_trivially_constructible<std::decay_t<Fn>, Fn>::value
     and std::is_trivially_destructible<std::decay_t<Fn>>::value
     and (sizeof(std::decay_t<Fn>)
          <= sizeof(std::reference_wrapper<std::decay_t<Fn>>))>;

public:
  template<typename Fn>
  constexpr auto operator()(Fn&& fn) const {
    return Curry<std::decay_t<Fn>>{std::forward<Fn>(fn)};
  }

  template<typename Fn, typename Arg, typename... Args>
  constexpr auto operator()(Fn& fn, Arg&& arg, Args&&... args) const
    -> Result<Fn&, Arg, Args...> {
    auto callable =
      boost::hana::demux
      (variant::visit(detail::construct<Result<Fn&, Arg, Args...>>))
      (boost::hana::if_(copyEfficient<Fn&>, fn, std::ref(fn)));
    return variant::visit(callable,
                          std::forward<Arg>(arg),
                          std::forward<Args>(args)...);
  }

  template<typename Fn, typename Arg, typename... Args>
  constexpr auto operator()(const Fn& fn, Arg&& arg, Args&&... args) const
    -> Result<const Fn&, Arg, Args...> {
    const auto callable =
      boost::hana::demux
      (variant::visit(detail::construct<Result<const Fn&, Arg, Args...>>))
      (boost::hana::if_(copyEfficient<const Fn&>, fn, std::ref(fn)));
    return variant::visit(callable,
                          std::forward<Arg>(arg),
                          std::forward<Args>(args)...);
  }

  template<typename Fn, typename Arg, typename... Args>
  constexpr auto operator()(Fn&& fn, Arg&& arg, Args&&... args) const
    -> Result<Fn, Arg, Args...> {
    auto callable =
      detail::demux
      (variant::visit(detail::construct<Result<Fn, Arg, Args...>>),
       std::forward<Fn>(fn));

    using FWD =
      std::conditional_t
      <std::is_const<std::remove_reference_t<Fn>>::value,
       const decltype(callable),
       decltype(callable)>;

    return visit(static_cast<FWD&&>(callable),
                 std::forward<Arg>(arg),
                 std::forward<Args>(args)...);
  }
};

template<typename... Args>
auto bind(Args&&... args) -> trait::InvokeResult_t<bind_fn, Args...> {
  return bind_fn{}(std::forward<Args>(args)...);
}
