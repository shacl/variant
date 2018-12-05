class map_fn {
  template<typename Fn, typename... Args>
  using Result =
    typename decltype
    (detail::sfinae::unpack
     (boost::hana::to_tuple
      (boost::hana::to_set
       (detail::possible_result_types_of
        (boost::hana::type_c<Fn>, boost::hana::type_c<Args>...))),
       detail::to_variant))::type;

  template<typename Fn>
  using Curry = detail::Curry<Fn, map_fn, Result>;

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
      (detail::construct<Result<Fn&, Arg, Args...>>)
      (boost::hana::if_(copyEfficient<Fn&>, fn, std::ref(fn)));

    return visit(callable, std::forward<Arg>(arg), std::forward<Args>(args)...);
  }

  template<typename Fn, typename Arg, typename... Args>
  constexpr auto operator()(const Fn& fn, Arg&& arg, Args&&... args) const
    -> Result<const Fn&, Arg, Args...> {
    const auto callable =
      boost::hana::demux
      (detail::construct<Result<const Fn&, Arg, Args...>>)
      (boost::hana::if_(copyEfficient<const Fn&>, fn, std::ref(fn)));

    return visit(callable, std::forward<Arg>(arg), std::forward<Args>(args)...);
  }

  template<typename Fn, typename Arg, typename... Args,
           std::enable_if_t
           <not std::is_lvalue_reference<Fn>::value, bool> = true>
  constexpr auto operator()(Fn&& fn, Arg&& arg, Args&&... args) const
    -> Result<Fn, Arg, Args...> {
    auto callable =
      detail::demux
      (detail::construct<Result<Fn, Arg, Args...>>,
       std::forward<Fn>(fn));

    using FWD =
      std::conditional_t
      <std::is_const<std::remove_reference_t<Fn>>::value,
       const decltype(callable),
       decltype(callable)>;

    return variant::visit(static_cast<FWD&&>(callable),
                          std::forward<Arg>(arg),
                          std::forward<Args>(args)...);
  }
};

template<typename... Args>
auto map(Args&&... args) -> trait::InvokeResult_t<map_fn, Args...> {
  return map_fn{}(std::forward<Args>(args)...);
}
