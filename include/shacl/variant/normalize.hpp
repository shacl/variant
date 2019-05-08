class normalize_fn {
  struct repack_fn {
    template<typename V, typename... TypeValues>
    constexpr auto operator()(V&& v, TypeValues...) const {
      using Result = Type<typename TypeValues::type...>;
      return visit(detail::construct<Result>, std::forward<V>(v));
    }
  };

  static constexpr repack_fn repack;

public:
  template<typename... Ts>
  constexpr auto operator(const Type<Ts...>& v) const {
    using namespace boost::hana;
    return unpack(to_set(make_tuple(type_c<std::decay_t<Ts>>...)),
                  partial(repack, v));
  }

  template<typename... Ts>
  constexpr auto operator(Type<Ts...>&& v) const {
    using namespace boost::hana;
    return unpack(to_set(make_tuple(type_c<std::decay_t<Ts>>...)),
                  partial(repack, std::move(v)));
  }
};

template<typename V>
auto normalize(V&& v) -> trait::InvokeResult_t<normalize_fn, V> {
  return normalize_fn{}(std::forward<V>(v));
}

template<typename... Ts>
using Normalized = decltype(normalize(std::declval<Type<Ts....>>()));
