class arguments_of_fn {
  template<std::size_t index, typename Variant>
  using Argument = decltype(get<index>(std::declval<Variant>()));

  template<typename Type, std::size_t... indices>
  static constexpr auto call(Type, std::index_sequence<indices...>) {
    using namespace boost::hana;
    using Variant = typename Type::type;
    return to_tuple(to_set(make_tuple(type_c<Argument<indices, Variant>>...)));
  }

public:
  template<typename Type,
           std::enable_if_t
           <IsInstance_v<std::decay_t<typename Type::type>>, bool> = true>
  constexpr auto operator()(Type type) const {
    constexpr auto indices =
      std::make_index_sequence<size_v<std::decay_t<typename Type::type>>>{};
    return call(type, indices);
  }
};

static constexpr arguments_of_fn arguments_of{};
