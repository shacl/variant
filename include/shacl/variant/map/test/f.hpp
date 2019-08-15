/**
 * In C++ 14 and 17, placement new and reinterpret cast are unavailable in
 * constexpr expressions. This is a fundemental barrier to implementing
 * constexpr Variant construction. That said, the functions of this library
 * are marked constexpr for forward compatability.
 **/
/*constexpr*/ auto f(boost::hana::size_t<0>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<1>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<2>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<3>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<4>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<5>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<6>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<7>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, vid);
}

/*constexpr*/ auto f(boost::hana::size_t<8>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<9>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<10>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<11>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<12>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<13>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<14>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<15>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<16>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<17>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<18>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<19>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<20>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<21>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<22>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<23>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::size_t<24>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<25>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<26>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<27>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<28>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<29>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<30>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::size_t<31>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::map(std::move(callable), std::move(vid));
}
