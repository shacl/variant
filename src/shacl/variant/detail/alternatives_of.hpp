class alternatives_of_fn {
public:
  template<typename Type,
           std::enable_if_t
           <IsInstance_v<std::decay_t<typename Type::type>>, bool> = true>
  constexpr auto operator()(Type type) const {
    using namespace boost::hana;
    return to_set(transform(arguments_of(type), decay));
  }
};

static constexpr alternatives_of_fn alternatives_of{};
