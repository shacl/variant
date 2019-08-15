target_sources(variant INTERFACE
  "${prefix}/shacl/variant/detail/alternatives_of.hpp"
  "${prefix}/shacl/variant/detail/arguments_of.hpp"
  "${prefix}/shacl/variant/detail/argument_type_product.hpp"
  "${prefix}/shacl/variant/detail/construct.hpp"
  "${prefix}/shacl/variant/detail/Curry.hpp"
  "${prefix}/shacl/variant/detail/decay.hpp"
  "${prefix}/shacl/variant/detail/demux.hpp"
  "${prefix}/shacl/variant/detail/invoke.hpp"
  "${prefix}/shacl/variant/detail/is_constructible.hpp"
  "${prefix}/shacl/variant/detail/possible_result_types_of.hpp"
  "${prefix}/shacl/variant/detail/sfinae.hpp"
  "${prefix}/shacl/variant/detail/sum.hpp"
  "${prefix}/shacl/variant/detail/to_variant.hpp")

add_subdirectory(sfinae)

if(shacl.variant.tests)
  add_subdirectory(alternatives_of/test)
  add_subdirectory(arguments_of/test)
  add_subdirectory(argument_type_product/test)
  add_subdirectory(construct/test)
  add_subdirectory(decay/test)
  add_subdirectory(invoke/test)
  add_subdirectory(is_constructible/test)
  add_subdirectory(possible_result_types_of/test)
  add_subdirectory(sum/test)
  add_subdirectory(to_variant/test)
endif()
