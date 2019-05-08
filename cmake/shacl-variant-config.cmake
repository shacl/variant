include(CMakeFindDependencyMacro)
find_dependency(shacl COMPONENTS trait ebo)

if(shacl-variant_FIND_QUIETLY)
  set(shacl-variant_FIND_QUIETLY_ARG QUIET)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/shacl-variant-targets.cmake")

find_package(mpark_variant ${shacl-variant_FIND_QUIETLY_ARG})
if(mpark_variant_FOUND)
  set_target_properties(shacl::variant PROPERTIES INTERFACE_CXX_STANDARD 14)
  target_link_libraries(shacl::variant-14 INTERFACE mpark_variant)
  target_link_libraries(shacl::variant INTERFACE
    $<$<VERSION_LESS:$<TARGET_PROPERTY:CXX_STANDARD>,17>:shacl::variant-14>)

else()
  if(NOT "${shacl-optional_FIND_QUIETLY_ARG}")
    message(WARNING "shacl::variant C++-14 support requires mpark_variant")
  endif()
  set_target_properties(shacl::variant PROPERTIES INTERFACE_CXX_STANDARD 17)
endif()

find_package(Boost 1.69 ${shacl-variant_FIND_QUIETLY_ARG})
if(Boost_FOUND)
  target_link_libraries(shacl::variant INTERFACE Boost::boost)
else()
  find_dependency(Hana 1.5)
  target_link_libraries(shacl::variant INTERFACE hana)
endif()
