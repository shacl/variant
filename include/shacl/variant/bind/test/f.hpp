/**
 * In C++ 14 and 17, placement new and reinterpret cast are unavailable in
 * constexpr expressions. This is a fundemental barrier to implementing
 * constexpr Variant construction. That said, the functions of this library
 * are marked constexpr for forward compatability.
 **/
/*constexpr*/ auto f(boost::hana::int_<0>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<1>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<2>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<3>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<4>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<5>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<6>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<7>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, vid);
}

/*constexpr*/ auto f(boost::hana::int_<8>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<9>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<10>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<11>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<12>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<13>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<14>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<15>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(callable, std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<16>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<17>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<18>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<19>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), vid);
}

/* constexpr */ auto f(boost::hana::int_<20>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<21>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<22>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<23>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), vid);
}

/*constexpr*/ auto f(boost::hana::int_<24>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<25>){
  callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<26>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<27>){
  callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<28>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<29>){
  const callable_fn callable{};
  shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<30>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}

/*constexpr*/ auto f(boost::hana::int_<31>){
  const callable_fn callable{};
  const shacl::Variant<int, double> vid = 0.0;
  return shacl::variant::bind(std::move(callable), std::move(vid));
}
