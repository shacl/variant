#ifndef SHACL_VARIANT_HPP
#define SHACL_VARIANT_HPP

#include "shacl/trait.hpp"
#include "shacl/ebo.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#if __cplusplus < 201703L
#include "mpark/variant.hpp"
#define PREFIX mpark
#else
#include <variant>
#define PREFIX std
#endif

#include "boost/hana/all.hpp"
#include "boost/hana/any.hpp"
#include "boost/hana/cartesian_product.hpp"
#include "boost/hana/fold.hpp"
#include "boost/hana/for_each.hpp"
#include "boost/hana/functional/apply.hpp"
#include "boost/hana/functional/demux.hpp"
#include "boost/hana/if.hpp"
#include "boost/hana/set.hpp"
#include "boost/hana/size.hpp"
#include "boost/hana/traits.hpp"
#include "boost/hana/transform.hpp"
#include "boost/hana/tuple.hpp"
#include "boost/hana/type.hpp"
#include "boost/hana/union.hpp"
#include "boost/hana/unpack.hpp"

#pragma GCC diagnostic pop

namespace shacl {
namespace variant {

template<typename... Args>
using Type = PREFIX::variant<Args...>;

template<typename T>
using size = PREFIX::variant_size<T>;

template <class T>
static constexpr std::size_t size_v = size<T>::value;

template <size_t I, class T>
using alternative = PREFIX::variant_alternative<I, T>;

template <size_t I, class T>
using alternative_t = PREFIX::variant_alternative_t<I, T>;

static constexpr size_t npos = PREFIX::variant_npos;

using PREFIX::holds_alternative;
using PREFIX::get;
using PREFIX::get_if;
using PREFIX::swap;

using bad_access = PREFIX::bad_variant_access;
using monostate = PREFIX::monostate;

using in_place_t = PREFIX::in_place_t;

static constexpr in_place_t in_place{};

template<typename T>
using in_place_type_t = PREFIX::in_place_type_t<T>;

template<typename T>
static constexpr in_place_type_t<T> in_place_type{};

template<std::size_t I>
using in_place_index_t = PREFIX::in_place_index_t<I>;

template<std::size_t I>
static constexpr in_place_index_t<I> in_place_index{};


#include "shacl/variant/IsInstance.hpp"

#include "shacl/variant/detail.hpp"
#include "shacl/variant/visit.hpp"
#include "shacl/variant/cast.hpp"
#include "shacl/variant/map.hpp"
#include "shacl/variant/bind.hpp"

}

template<typename... Ts>
using Variant = variant::Type<Ts...>;

}

#undef PREFIX
#endif
