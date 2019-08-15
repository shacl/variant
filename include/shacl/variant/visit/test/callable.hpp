struct callable_fn {
  constexpr int operator()(int&) & { return 0; }
  constexpr int operator()(double&) & { return 1; }
  constexpr int operator()(const int&) & { return 2; }
  constexpr int operator()(const double&) & { return 3; }

  constexpr int operator()(int&) const & { return 4; }
  constexpr int operator()(double&) const & { return 5; }
  constexpr int operator()(const int&) const & { return 6; }
  constexpr int operator()(const double&) const & { return 7; }

  constexpr int operator()(int&&) & { return 8; }
  constexpr int operator()(double&&) & { return 9; }
  constexpr int operator()(const int&&) & { return 10; }
  constexpr int operator()(const double&&) & { return 11; }

  constexpr int operator()(int&&) const & { return 12; }
  constexpr int operator()(double&&) const & { return 13; }
  constexpr int operator()(const int&&) const & { return 14; }
  constexpr int operator()(const double&&) const & { return 15; }

  constexpr int operator()(int&) && { return 16; }
  constexpr int operator()(double&) && { return 17; }
  constexpr int operator()(const int&) && { return 18; }
  constexpr int operator()(const double&) && { return 19; }

  constexpr int operator()(int&) const && { return 20; }
  constexpr int operator()(double&) const && { return 21; }
  constexpr int operator()(const int&) const && { return 22; }
  constexpr int operator()(const double&) const && { return 23; }

  constexpr int operator()(int&&) && { return 24; }
  constexpr int operator()(double&&) && { return 25; }
  constexpr int operator()(const int&&) && { return 26; }
  constexpr int operator()(const double&&) && { return 27; }

  constexpr int operator()(int&&) const && { return 28; }
  constexpr int operator()(double&&) const && { return 29; }
  constexpr int operator()(const int&&) const && { return 30; }
  constexpr int operator()(const double&&) const && { return 31; }
};
