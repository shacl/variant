struct callable_fn {
  template<size_t i>
  static constexpr auto size_c = boost::hana::size_c<i>;

  constexpr auto operator()(int&) & { return size_c<0>; }
  constexpr auto operator()(double&) & { return size_c<1>; }
  constexpr auto operator()(const int&) & { return size_c<2>; }
  constexpr auto operator()(const double&) & { return size_c<3>; }

  constexpr auto operator()(int&) const & { return size_c<4>; }
  constexpr auto operator()(double&) const & { return size_c<5>; }
  constexpr auto operator()(const int&) const & { return size_c<6>; }
  constexpr auto operator()(const double&) const & { return size_c<7>; }

  constexpr auto operator()(int&&) & { return size_c<8>; }
  constexpr auto operator()(double&&) & { return size_c<9>; }
  constexpr auto operator()(const int&&) & { return size_c<10>; }
  constexpr auto operator()(const double&&) & { return size_c<11>; }

  constexpr auto operator()(int&&) const & { return size_c<12>; }
  constexpr auto operator()(double&&) const & { return size_c<13>; }
  constexpr auto operator()(const int&&) const & { return size_c<14>; }
  constexpr auto operator()(const double&&) const & { return size_c<15>; }

  constexpr auto operator()(int&) && { return size_c<16>; }
  constexpr auto operator()(double&) && { return size_c<17>; }
  constexpr auto operator()(const int&) && { return size_c<18>; }
  constexpr auto operator()(const double&) && { return size_c<19>; }

  constexpr auto operator()(int&) const && { return size_c<20>; }
  constexpr auto operator()(double&) const && { return size_c<21>; }
  constexpr auto operator()(const int&) const && { return size_c<22>; }
  constexpr auto operator()(const double&) const && { return size_c<23>; }

  constexpr auto operator()(int&&) && { return size_c<24>; }
  constexpr auto operator()(double&&) && { return size_c<25>; }
  constexpr auto operator()(const int&&) && { return size_c<26>; }
  constexpr auto operator()(const double&&) && { return size_c<27>; }

  constexpr auto operator()(int&&) const && { return size_c<28>; }
  constexpr auto operator()(double&&) const && { return size_c<29>; }
  constexpr auto operator()(const int&&) const && { return size_c<30>; }
  constexpr auto operator()(const double&&) const && { return size_c<31>; }
};
