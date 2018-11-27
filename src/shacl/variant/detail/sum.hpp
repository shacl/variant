class sum_fn {
public:
  template<typename... Ts,
           typename = void_t<trait::InvokeResult_t<alternatives_of_fn, Ts>...>,
           std::enable_if_t
           <boost::hana::all
            (boost::hana::make_tuple
             (boost::hana::bool_c<IsInstance_v<typename Ts::type>>)),
            bool> = true>
  constexpr auto operator()(Ts... ts) const {
    using namespace boost::hana;
    return unpack(fold(make_tuple(alternatives_of(ts)...), make_set(), union_),
                  to_variant)
  }
};

static constexpr sum_fn sum{};

