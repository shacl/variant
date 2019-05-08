namespace detail {

#include "shacl/variant/detail/arguments_of.hpp"
#include "shacl/variant/detail/decay.hpp"
#include "shacl/variant/detail/alternatives_of.hpp"
#include "shacl/variant/detail/invoke.hpp"

#define DECLTYPE_AUTO_RETURN(...)   \
  -> decltype(__VA_ARGS__)          \
  { return (__VA_ARGS__); }

#include "shacl/variant/detail/sfinae.hpp"
#include "shacl/variant/detail/argument_type_product.hpp"
#include "shacl/variant/detail/possible_result_types_of.hpp"

#undef DECLTYPE_AUTO_RETURN

#include "shacl/variant/detail/is_constructible.hpp"
#include "shacl/variant/detail/to_variant.hpp"
#include "shacl/variant/detail/sum.hpp"

#include "shacl/variant/detail/demux.hpp"
#include "shacl/variant/detail/construct.hpp"
#include "shacl/variant/detail/Curry.hpp"

}
