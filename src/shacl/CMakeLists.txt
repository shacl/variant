target_sources(variant INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/variant.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant.hpp>)

add_subdirectory(variant)
