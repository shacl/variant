struct callable_fn {
  template<size_t i>
  static constexpr auto int_c = boost::hana::int_c<i>;

  template<typename T>
  static constexpr auto wrap(T t) {
    return shacl::Variant<T, boost::hana::int_<99>>{t};
  }

  constexpr auto operator()(int&) & { return wrap(int_c<0>); }
  constexpr auto operator()(double&) & { return wrap(int_c<1>); }
  constexpr auto operator()(const int&) & { return wrap(int_c<2>); }
  constexpr auto operator()(const double&) & { return wrap(int_c<3>); }

  constexpr auto operator()(int&) const & { return wrap(int_c<4>); }
  constexpr auto operator()(double&) const & { return wrap(int_c<5>); }
  constexpr auto operator()(const int&) const & { return wrap(int_c<6>); }
  constexpr auto operator()(const double&) const & { return wrap(int_c<7>); }

  constexpr auto operator()(int&&) & { return wrap(int_c<8>); }
  constexpr auto operator()(double&&) & { return wrap(int_c<9>); }
  constexpr auto operator()(const int&&) & { return wrap(int_c<10>); }
  constexpr auto operator()(const double&&) & { return wrap(int_c<11>); }

  constexpr auto operator()(int&&) const & { return wrap(int_c<12>); }
  constexpr auto operator()(double&&) const & { return wrap(int_c<13>); }
  constexpr auto operator()(const int&&) const & { return wrap(int_c<14>); }
  constexpr auto operator()(const double&&) const & { return wrap(int_c<15>); }

  constexpr auto operator()(int&) && { return wrap(int_c<16>); }
  constexpr auto operator()(double&) && { return wrap(int_c<17>); }
  constexpr auto operator()(const int&) && { return wrap(int_c<18>); }
  constexpr auto operator()(const double&) && { return wrap(int_c<19>); }

  constexpr auto operator()(int&) const && { return wrap(int_c<20>); }
  constexpr auto operator()(double&) const && { return wrap(int_c<21>); }
  constexpr auto operator()(const int&) const && { return wrap(int_c<22>); }
  constexpr auto operator()(const double&) const && { return wrap(int_c<23>); }

  constexpr auto operator()(int&&) && { return wrap(int_c<24>); }
  constexpr auto operator()(double&&) && { return wrap(int_c<25>); }
  constexpr auto operator()(const int&&) && { return wrap(int_c<26>); }
  constexpr auto operator()(const double&&) && { return wrap(int_c<27>); }

  constexpr auto operator()(int&&) const && { return wrap(int_c<28>); }
  constexpr auto operator()(double&&) const && { return wrap(int_c<29>); }
  constexpr auto operator()(const int&&) const && { return wrap(int_c<30>); }
  constexpr auto operator()(const double&&) const && { return wrap(int_c<31>); }
};
