struct bind_fn {
  template<typename Fn>
  class Curry : ebo::Type<Fn> {
    using Parent = ebo::Type<Fn>;

  public:
    using ebo::Type<Fn>::Type;

    template<typename... Args>
    constexpr auto operator()(Args&& args) const &
      -> Result<const Parent&, Args...> {
      decltype(auto) fn = Parent::get(ebo::index<0>);
      return bind_fn{}(fn, std::forward<Args>(args)...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) &&
      -> Result<Parent&&, Args...> {
      return bind_fn{}(Parent::get(ebo::index<0>),
                       std::forward<Args>(args)...);
    }
  };

  template<typename Fn, typename Args...>
  auto Result =
    typename decltype
    (boost::hana::unpack
     (boost::hana::transform
      (boost::hana::cartesian_product
       (boost::hana::make_tuple
        (detail::arguments_of(boost::hana::type_c<Args>)...)),
       boost::hana::reverse_partial
       (boost::hana::unpack,
        boost::hana::partial(detail::invoke, boost::hana::type_c<Fn>))),
      detail::sum))::type;

public:
  template<typename Fn>
  constexpr auto operator()(Fn&& fn) const {
    return Curry<std::decay_t<Fn>>{std::forward<Fn>(fn)};
  }

  template<typename Fn, typename... Args>
  constexpr auto operator()(Fn&& fn, Args&&... args) const
    -> Result<Fn, Args...> {
    return visit(boost::hana::compose
                 (visit(detail::construct<Result<Fn, Args...>>),
                  std::forward<Fn>(fn)),
                 std::forward<Args>(args)...);
  }
};

template<typename Args>
auto bind(Args&&... args) -> trait::InvokeResult_t<bind_fn, Args...> {
  return bind_fn{}(std::forward<Args>(args)...);
}
