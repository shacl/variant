struct visit_fn {
  template<typename Tuple,
           std::enable_if_t
           <boost::hana::size(Tuple{}) == hana::size_c<0>, bool> = true>
  static constexpr auto unwrap(Tuple t) {
    return t[hana::size_c<0>];
  }

  template<typename Fn, typename... Args>
  using Results =
    typename decltype
    (unwrap
     (boost::hana::to_tuple
      (boost::hana::to_set
       (boost::hana::transform
        (boost::hana::cartesian_product
         (boost::hana::make_tuple
          (detail::arguments_of(type_c<Args>))),
         boost::hana::reverse_partial
         (boost::hana::unpack,
          boost::hana::partial
          (detail::invoke, boost::hana::type_c<Fn>)))))))::type;

  template<typename Fn>
  class Curry : ebo::Type<Fn> {
    using Parent = ebo::Type<Fn>;

  public:
    using ebo::Type<Fn>::Type;

    template<typename... Args>
    constexpr auto operator()(Args&& args) const &
      -> Result<const Parent&, Args...> {
      decltype(auto) fn = Parent::get(ebo::index<0>);
      return visit_fn{}(fn, std::forward<Args>(args)...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) &&
      -> Result<Parent&&, Args...> {
      return visit_fn{}(Parent::get(ebo::index<0>),
                        std::forward<Args>(args)...);
    }
  };

public:
  template<typename Fn>
  constexpr auto operator()(Fn&& fn) const {
    return Curry<std::decay_t<Fn>>{std::forward<Fn>(fn)};
  }

  template<typename... Args>
  constexpr auto
  operator()(Args&&... args) const -> Result<Args...> {
    return PREFIX::visit(std::forward<Args>(args)...);
  }
};

template<typename Args>
auto visit(Args&&... args) -> trait::InvokeResult_t<visit_fn, Args...> {
  return visit_fn{}(std::forward<Args>(args)...);
}
