target_sources(variant INTERFACE
  $<BUILD_INTERFACE:
    ${CMAKE_CURRENT_LIST_DIR}/IsInstance.hpp
    ${CMAKE_CURRENT_LIST_DIR}/bind.hpp
    ${CMAKE_CURRENT_LIST_DIR}/cast.hpp
    ${CMAKE_CURRENT_LIST_DIR}/detail.hpp
    ${CMAKE_CURRENT_LIST_DIR}/map.hpp
    ${CMAKE_CURRENT_LIST_DIR}/normalize.hpp
    ${CMAKE_CURRENT_LIST_DIR}/visit.hpp>
  $<INSTALL_INTERFACE:
    include/shacl/variant/IsInstance.hpp
    include/shacl/variant/bind.hpp
    include/shacl/variant/cast.hpp
    include/shacl/variant/detail.hpp
    include/shacl/variant/map.hpp
    include/shacl/variant/normalize.hpp
    include/shacl/variant/visit.hpp>)

add_subdirectory(detail)

if(variant.tests)
  add_subdirectory(visit/test)
  add_subdirectory(cast/test)
  add_subdirectory(map/test)
  add_subdirectory(bind/test)
endif()
