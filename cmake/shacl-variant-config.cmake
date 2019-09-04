include(CMakeFindDependencyMacro)

if(NOT TARGET shacl-trait)
  find_dependency(shacl-trait)
endif()

if(NOT TARGET shacl-ebo)
  find_dependency(shacl-ebo)
endif()

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
  if(NOT "${shacl-variant_FIND_QUIETLY_ARG}")
    message(WARNING
      "shacl::variant requiring C++17 because mpark_variant was not found")
  endif()
  set_target_properties(shacl::variant PROPERTIES INTERFACE_CXX_STANDARD 17)
endif()

find_package(Boost 1.69 ${shacl-variant_FIND_QUIETLY_ARG})
if(Boost_FOUND)
  target_link_libraries(shacl::variant INTERFACE Boost::boost)
else()
  #TODO version 1.5 of hana is required, but the installed versions 
  #of hana do not correctly export the version number.
  find_dependency(Hana)
  target_link_libraries(shacl::variant INTERFACE hana)
endif()
