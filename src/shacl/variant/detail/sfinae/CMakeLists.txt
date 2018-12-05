target_sources(variant INTERFACE
  $<BUILD_INTERFACE:
    ${CMAKE_CURRENT_LIST_DIR}/partial.hpp
    ${CMAKE_CURRENT_LIST_DIR}/reverse_partial.hpp
    ${CMAKE_CURRENT_LIST_DIR}/transform.hpp
    ${CMAKE_CURRENT_LIST_DIR}/unpack.hpp>
  $<INSTALL_INTERFACE:
    include/shacl/variant/detail/sfinae/partial.hpp
    include/shacl/variant/detail/sfinae/reverse_partial.hpp
    include/shacl/variant/detail/sfinae/transform.hpp
    include/shacl/variant/detail/sfinae/unpack.hpp>)
