target_sources(variant INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/IsInstance.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/bind.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/cast.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/detail.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/map.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/normalize.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/visit.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/IsInstance.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/bind.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/cast.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/detail.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/map.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/normalize.hpp>
  $<INSTALL_INTERFACE:include/shacl/variant/visit.hpp>)

add_subdirectory(detail)

if(variant.tests)
  add_subdirectory(visit/test)
  add_subdirectory(cast/test)
  add_subdirectory(map/test)
  add_subdirectory(bind/test)
endif()
