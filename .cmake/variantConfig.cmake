find_dependency(shacl REQUIRED COMPONENTS trait ebo)
find_dependency(mpark_variant REQUIRED)
find_package(Boost 1.61)
if(NOT Boost_FOUND)
  find_package(hana REQUIRED)
  add_library(Boost::boost ALIAS hana)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/variantTargets.cmake")
