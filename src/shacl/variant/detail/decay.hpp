struct decay_fn {
  template<typename Type>
  constexpr auto operator()(Type) const {
    return boost::hana::type_c<std::decay_t<Type::type>>
  }
};

static constexpr decay_fn decay{};
