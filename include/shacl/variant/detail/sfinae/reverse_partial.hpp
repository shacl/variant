struct reverse_partial_fn {
  template<typename index_sequence, typename Fn, typename... Leading>
  struct Closure;

  template <std::size_t... indices,
            typename Fn,
            typename... Trailing>
  struct Closure<std::index_sequence<indices...>, Fn, Trailing...> {
    boost::hana::basic_tuple<Fn, Trailing...> storage;

    template <typename... Args>
    constexpr Closure(Args&&... args) :
    storage{std::forward<Args>(args)...}{}

    template <typename... Leading>
    constexpr auto operator()(Leading&&... leading) &
      DECLTYPE_AUTO_RETURN(
        boost::hana::at_c<0>(storage)
        (std::forward<Leading>(leading)...,
         boost::hana::at_c<indices+1>(storage)...))

    template <typename... Leading>
    constexpr auto operator()(Leading&&... leading) const&
      DECLTYPE_AUTO_RETURN(
        boost::hana::at_c<0>(storage)
        (std::forward<Leading>(leading)...,
         boost::hana::at_c<indices+1>(storage)...))

    template <typename... Leading>
    constexpr auto operator()(Leading&&... leading) &&
      DECLTYPE_AUTO_RETURN(
        std::move(boost::hana::at_c<0>(storage))
        (std::forward<Leading>(leading)...,
         std::move(boost::hana::at_c<indices+1>(storage)...)))

    template <typename... Leading>
    constexpr auto operator()(Leading&&... leading) const&&
      DECLTYPE_AUTO_RETURN(
        std::move(boost::hana::at_c<0>(storage))
        (std::forward<Leading>(leading)...,
         std::move(boost::hana::at_c<indices+1>(storage)...)))
  };


  template <typename Fn, typename... Trailing>
  constexpr auto operator()(Fn&& fn, Trailing&&... trailing) const {
    return
      Closure
      <std::make_index_sequence<sizeof...(Trailing)>,
       std::decay_t<Fn>, std::decay_t<Trailing>...>
      {std::forward<Fn>(fn), std::forward<Trailing>(trailing)...};
  }
};

static constexpr reverse_partial_fn reverse_partial{};
