template<typename Fn, typename Host, template<typename...> class Result >
class Curry : ebo::Type<Fn> {
  using Parent = ebo::Type<Fn>;

public:
  using ebo::Type<Fn>::Type;

  template<typename... Args>
  constexpr auto operator()(Args&&... args) &
    -> Result<Fn&, Args...> {
    return Host{}(Parent::get(ebo::index<0>), std::forward<Args>(args)...);
  }

  template<typename... Args>
  constexpr auto operator()(Args&&... args) const &
    -> Result<const Fn&, Args...> {
    return Host{}(Parent::get(ebo::index<0>), std::forward<Args>(args)...);
  }

  template<typename... Args>
  auto operator()(Args&&... args) &&
    -> Result<Fn&&, Args...> {
    return Host{}(std::move(Parent::get(ebo::index<0>)),
                    std::forward<Args>(args)...);
  }

  template<typename... Args>
  auto operator()(Args&&... args) const &&
    -> Result<const Fn&&, Args...> {
    return Host{}(std::move(Parent::get(ebo::index<0>)),
                    std::forward<Args>(args)...);
  }
};
