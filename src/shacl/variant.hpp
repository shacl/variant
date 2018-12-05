#ifndef SHACL_VARIANT_HPP
#define SHACL_VARIANT_HPP

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#if __cplusplus < 201703L
#include "mpark/variant.hpp"
#define PREFIX mpark
#else
#include <variant>
#define PREFIX std
#endif

#include "boost/hana.hpp"
#pragma GCC diagnostic pop

#include "shacl/trait.hpp"
#include "shacl/ebo.hpp"

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
