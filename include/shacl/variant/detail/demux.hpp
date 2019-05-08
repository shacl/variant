// Why not use boost::hana::demux?

// At the time of writing, the callable resulting from a hana::demux call
// does not respect const rvalue reference overloads of the composed callables.

class demux_fn {
  template<typename Indices, typename Root, typename... Leaves>
  class Closure;

  template<std::size_t... indices, typename Root, typename... Leaves>
  class Closure<std::index_sequence<indices...>, Root, Leaves...> :
    ebo::Type<Root, Leaves...> {

    using Parent = ebo::Type<Root, Leaves...>;

  public:
    using Parent::Parent;

    template<typename... Args>
    constexpr auto operator()(Args&&... args) & ->
      trait::InvokeResult_t
      <Root&, trait::InvokeResult_t<Leaves&, Args...>...> {
      return
        Parent::get(ebo::index<0>)
        (static_cast
         <trait::InvokeResult_t<Leaves&, Args...>&&>
         (Parent::get(ebo::index<indices + 1>)
          (std::forward<Args>(args)...))...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) const & ->
      trait::InvokeResult_t
      <const Root&, trait::InvokeResult_t<const Leaves&, Args...>...> {
      return
        Parent::get(ebo::index<0>)
        (static_cast
         <trait::InvokeResult_t<const Leaves&, Args...>&&>
         (Parent::get(ebo::index<indices + 1>)
          (std::forward<Args>(args)...))...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) && ->
      trait::InvokeResult_t
      <Root&&, trait::InvokeResult_t<Leaves&&, Args...>...> {
      return
        std::move(Parent::get(ebo::index<0>))
        (static_cast
         <trait::InvokeResult_t<Leaves&&, Args...>&&>
         (std::move(Parent::get(ebo::index<indices + 1>))
          (std::forward<Args>(args)...))...);
    }

    template<typename... Args>
    constexpr auto operator()(Args&&... args) const && ->
      trait::InvokeResult_t
      <const Root&&, trait::InvokeResult_t<const Leaves&&, Args...>...> {
      return
        std::move(Parent::get(ebo::index<0>))
        (static_cast
         <trait::InvokeResult_t<const Leaves&&, Args...>&&>
         (std::move(Parent::get(ebo::index<indices + 1>))
          (std::forward<Args>(args)...))...);
    }
  };

public:
  template<typename Root, typename Leaf, typename... Leaves>
  constexpr auto
  operator()(Root&& root, Leaf&& leaf, Leaves&&... leaves) const {
    return
    Closure<std::make_index_sequence<sizeof...(Leaves) + 1>,
            std::decay_t<Root>, std::decay_t<Leaf>, std::decay_t<Leaves>...> {
      std::forward<Root>(root),
      std::forward<Leaf>(leaf),
      std::forward<Leaves>(leaves)...
    };
  }
};

static constexpr demux_fn demux{};
