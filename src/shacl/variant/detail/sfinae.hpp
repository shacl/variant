// These are basically just reimplementations of higher order functions
// provided by boost::hana. The distinction is that these implementations
// are sfinae-friendly.

namespace sfinae {

#include "shacl/variant/detail/sfinae/partial.hpp"
#include "shacl/variant/detail/sfinae/reverse_partial.hpp"
#include "shacl/variant/detail/sfinae/unpack.hpp"
#include "shacl/variant/detail/sfinae/transform.hpp"

}
