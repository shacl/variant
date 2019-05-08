target_sources(variant INTERFACE
  "${prefix}/shacl/variant/IsInstance.hpp"
  "${prefix}/shacl/variant/bind.hpp"
  "${prefix}/shacl/variant/cast.hpp"
  "${prefix}/shacl/variant/detail.hpp"
  "${prefix}/shacl/variant/map.hpp"
  "${prefix}/shacl/variant/normalize.hpp"
  "${prefix}/shacl/variant/visit.hpp")

add_subdirectory(detail)

if(variant.tests)
  add_subdirectory(visit/test)
  add_subdirectory(cast/test)
  add_subdirectory(map/test)
  add_subdirectory(bind/test)
endif()
