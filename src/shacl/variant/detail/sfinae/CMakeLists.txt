target_sources(variant INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/partial.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/reverse_partial.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/transform.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/unpack.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/detail/sfinae/partial.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/detail/sfinae/reverse_partial.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/detail/sfinae/transform.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/detail/sfinae/unpack.hpp>)
