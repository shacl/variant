struct visit_fn {
  template<typename Tuple,
           std::enable_if_t
           <boost::hana::size(Tuple{}) == boost::hana::size_c<1>,
            bool> = true>
  static constexpr auto unwrap(Tuple t)
    -> std::decay_t<decltype(t[boost::hana::size_c<0>])>{
    return t[boost::hana::size_c<0>];
  }

public:
  template<typename Fn, typename... Args>
  using Result =
    typename decltype
    (unwrap
     (boost::hana::to_tuple
      (boost::hana::to_set
       (detail::possible_result_types_of
        (boost::hana::type_c<Fn>, boost::hana::type_c<Args>...)))))::type;

protected:
  template<typename Fn>
  using Curry = detail::Curry<Fn, visit_fn, Result>;

public:
  template<typename Fn>
  constexpr auto operator()(Fn&& fn) const {
    return Curry<std::decay_t<Fn>>{std::forward<Fn>(fn)};
  }

  template<typename Fn, typename... Args>
  constexpr auto
  operator()(Fn&& fn, Args&&... args) const -> Result<Fn, Args...> {
    return PREFIX::visit(std::forward<Fn>(fn), std::forward<Args>(args)...);
  }
};

template<typename... Args>
constexpr auto visit(Args&&... args) -> trait::InvokeResult_t<visit_fn, Args...> {
  return visit_fn{}(std::forward<Args>(args)...);
}
