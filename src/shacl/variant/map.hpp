struct map_fn {
  template<typename Fn>
  class Curry : ebo::Type<Fn> {
    using Parent = ebo::Type<Fn>;

  public:
    using ebo::Type<Fn>::Type;

    template<typename... Args>
    constexpr auto operator()(Args&& args) const &
      -> Result<const Parent&, Args...> {
      decltype(auto) fn = Parent::get(ebo::index<0>);
      return map_fn{}(fn, std::forward<Args>(args)...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) &&
      -> Result<Parent&&, Args...> {
      return map_fn{}(Parent::get(ebo::index<0>),
                      std::forward<Args>(args)...);
    }
  };

  template<typename Fn, typename Args...>
  auto Result =
    typename decltype
    (boost::hana::unpack
     (boost::hana::to_set
      (boost::hana::transform
       (boost::hana::cartesian_product
        (boost::hana::make_tuple
         (detail::arguments_of(boost::hana::type_c<Args>)...)),
        boost::hana::reverse_partial
        (boost::hana::unpack,
         boost::hana::partial(detail::invoke, boost::hana::type_c<Fn>)))),
      detail::to_variant))::type;

public:
  template<typename Fn>
  constexpr auto operator()(Fn&& fn) const {
    return Curry<std::decay_t<Fn>>{std::forward<Fn>(fn)};
  }

  template<typename Fn, typename... Args>
  constexpr auto operator()(Fn&& fn, Args&&... args) const
    -> Result<Fn, Args...> {
    return visit(boost::hana::compose(detail::construct<Result<Fn, Args...>>,
                               std::forward<Fn>(fn)),
                 std::forward<Args>(args)...);
  }
};

template<typename Args>
auto map(Args&&... args) -> trait::InvokeResult_t<map_fn, Args...> {
  return map_fn{}(std::forward<Args>(args)...);
}
