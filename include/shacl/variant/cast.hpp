struct bad_cast : std::bad_cast {};

template<typename T, typename... Ts>
class cast_fn {
  using Result = Type<T, Ts...>;

  struct overload_fn {
    template<typename Arg,
             std::enable_if_t
             <std::is_constructible<Result, Arg>::value, bool> = true>
    constexpr Result operator()(Arg&& arg) const {
      return {std::forward<Arg>(arg)};
    }

    template<typename Arg,
             std::enable_if_t
             <not std::is_constructible<Result, Arg>::value, bool> = true>
    constexpr Result operator()(Arg&&) const {
      throw bad_cast{};
    }
  };

  template<typename Type,
           std::enable_if_t
           <IsInstance_v<std::decay_t<typename Type::type>>, bool> = true>
  static constexpr bool possible(Type type){
    return boost::hana::any
            (boost::hana::transform
             (detail::arguments_of(type),
              boost::hana::partial
              (detail::is_constructible, boost::hana::type_c<Result>))).value;
  }

public:
  template<typename V,
           std::enable_if_t<possible(boost::hana::type_c<V>), bool> = true>
  constexpr auto operator()(V&& v) const {
    return visit(overload_fn{}, std::forward<V>(v));
  }
};

template<typename... Ts>
static constexpr cast_fn<Ts...> cast{};
