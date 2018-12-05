struct transform_fn {
protected:
  template<std::size_t... indices, typename Tuple, typename Fn>
  static constexpr auto
  call(std::index_sequence<indices...>, Tuple&& tuple, Fn&& fn)
    DECLTYPE_AUTO_RETURN(
      boost::hana::make_tuple
      (std::forward<Fn>(fn)
       (boost::hana::at_c<indices>
        (std::forward<Tuple>(tuple)))...))

public:
  template<typename Tuple, typename Fn>
  constexpr auto operator()(Tuple&& tuple, Fn&& fn) const
    DECLTYPE_AUTO_RETURN(
      transform_fn::call
      (std::make_index_sequence
       <decltype(boost::hana::size(tuple))::value>{},
       std::forward<Tuple>(tuple),
       std::forward<Fn>(fn)))
};

static constexpr transform_fn transform{};
