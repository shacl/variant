struct partial_fn {
  template<typename index_sequence, typename Fn, typename... Leading>
  struct Closure;

  template <std::size_t... indices,
            typename Fn,
            typename... Leading>
  struct Closure<std::index_sequence<indices...>, Fn, Leading...> {
    boost::hana::basic_tuple<Fn, Leading...> storage;

    template <typename... Args>
    constexpr Closure(Args&&... args) :
    storage{std::forward<Args>(args)...}{}

    template <typename... Trailing>
    constexpr auto operator()(Trailing&&... trailing) &
      DECLTYPE_AUTO_RETURN(
        boost::hana::at_c<0>(storage)
        (boost::hana::at_c<indices+1>(storage)...,
         std::forward<Trailing>(trailing)...))

    template <typename... Trailing>
    constexpr auto operator()(Trailing&&... trailing) const&
      DECLTYPE_AUTO_RETURN(
        boost::hana::at_c<0>(storage)
        (boost::hana::at_c<indices+1>(storage)...,
         std::forward<Trailing>(trailing)...))

    template <typename... Trailing>
    constexpr auto operator()(Trailing&&... trailing) &&
      DECLTYPE_AUTO_RETURN(
        std::move(boost::hana::at_c<0>(storage))
        (std::move(boost::hana::at_c<indices+1>(storage)...),
         std::forward<Trailing>(trailing)...))

    template <typename... Trailing>
    constexpr auto operator()(Trailing&&... trailing) const&&
      DECLTYPE_AUTO_RETURN(
        std::move(boost::hana::at_c<0>(storage))
        (std::move(boost::hana::at_c<indices+1>(storage)...),
         std::forward<Trailing>(trailing)...))
  };


  template <typename Fn, typename... Leading>
  constexpr auto operator()(Fn&& fn, Leading&&... leading) const {
    return
      Closure
      <std::make_index_sequence<sizeof...(Leading)>,
       std::decay_t<Fn>, std::decay_t<Leading>...>
      {std::forward<Fn>(fn), std::forward<Leading>(leading)...};
  }
};

static constexpr partial_fn partial{};
