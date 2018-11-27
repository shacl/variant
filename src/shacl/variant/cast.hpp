struct bad_cast : std::bad_cast {};

template<typename T, typename... Ts>
class cast_fn {
  using Result = Type<T, Ts...>;

  struct overload_fn {
    template<typename Arg,
             std::enable_if_t
             <std::is_constructible<Result, Arg>::value, bool> = true>
    constexpr Result operator()(Arg&& arg){
      return {std::forward<Arg>(arg)};
    }

    template<typename Arg,
             std::enable_if_t
             <not std::is_constructible<Result, Arg>::value, bool> = true>
    constexpr Result operator()(Arg&& arg){
      throw bad_cast{};
    }
  };

  static constexpr overload_fn overload{};

public:
  template<typename... Us>
  constexpr auto operator()(const Type<Us...>& v) const {
    return visit(overload, v);
  }

  template<typename... Us>
  constexpr auto operator()(Type<Us...>&& v) const {
    return visit(overload, std::move(v));
  }
};

template<typename... Ts>
static constexpr cast_fn<Ts...> cast{};
