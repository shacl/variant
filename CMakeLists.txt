cmake_minimum_required(VERSION 3.12)

set(subproject OFF)
if(DEFINED PROJECT_NAME)
  set(subproject ON)
endif()

project(shacl-variant
  VERSION 0.2.1
  DESCRIPTION "Utilities for (and optional C++14 backport of) std::variant"
  HOMEPAGE_URL "https://xcp-stash.lanl.gov/projects/SCL/repos/variant"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/.cmake")
include(CMakeDependentOption)
include(CMakePackageConfigHelpers)
include(CTest)
include(Git/Submodule/Packages)

#
# The file referenced in this block used by version branches of shacl::variant
# to fix the version of the dependencies found by the find_package overload
# provided by Git Submodule Packages.
#
if(EXISTS "${PROJECT_SOURCE_DIR}/cmake/specification.cmake")
  set(git.submodule.packages.specification
    "${PROJECT_SOURCE_DIR}/cmake/specification.cmake" CACHE FILEPATH
    "(READ ONLY) Path to consumed git submodule packages specification file" FORCE)
  include("${PROJECT_SOURCE_DIR}/cmake/specification.cmake")
endif()

CMAKE_DEPENDENT_OPTION(shacl.variant.tests
  "Build the variant tests and integrate with ctest"
  ON "BUILD_TESTING; NOT subproject" OFF)

add_library(variant INTERFACE)
add_library(shacl::variant ALIAS variant)

if(shacl.variant.tests)
  include(Warnings)
  include(Sanitizers)

  configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/CTestCustom.cmake"
    "${PROJECT_BINARY_DIR}/CTestCustom.cmake"
    COPYONLY)

  set(CMAKE_CXX_EXTENSIONS OFF)

  add_library(shacl::variant::testing IMPORTED INTERFACE)

  set_target_properties(shacl::variant::testing PROPERTIES
    INTERFACE_WARN_ALL ON
    INTERFACE_WARN_ERROR ON)

  set_property(TARGET shacl::variant::testing APPEND PROPERTY
    COMPATIBLE_INTERFACE_BOOL
    WARN_ALL WARN_ERROR)

  find_package(Catch2 REQUIRED)
  target_link_libraries(shacl::variant::testing INTERFACE
    shacl::cmake::Warnings_CXX
    shacl::cmake::Sanitizers_CXX
    Catch2::Catch2
    shacl::variant)
endif()

find_package(shacl REQUIRED COMPONENTS trait ebo)
target_link_libraries(variant INTERFACE
  shacl::trait
  shacl::ebo)

find_package(Boost 1.69 QUIET)
if(Boost_FOUND)
  target_link_libraries(variant INTERFACE $<BUILD_INTERFACE:Boost::boost>)
else()
  find_package(Hana 1.5 REQUIRED)
  target_link_libraries(variant INTERFACE $<BUILD_INTERFACE:hana>)
endif()

add_library(variant-14 INTERFACE)
add_library(shacl::variant-14 ALIAS variant-14)

find_package(mpark_variant)
if(mpark_variant_FOUND)
  target_link_libraries(variant-14 INTERFACE $<BUILD_INTERFACE:mpark_variant>)

  string(CONCAT generator
    "$<BUILD_INTERFACE:"
      "$<$<VERSION_LESS:"
        "$<TARGET_PROPERTY:CXX_STANDARD>,17>:shacl::variant-14>>")

  target_link_libraries(variant INTERFACE ${generator})
  unset(generator)

  target_compile_features(variant INTERFACE $<BUILD_INTERFACE:cxx_std_14>)
else()
  target_compile_features(variant INTERFACE $<BUILD_INTERFACE:cxx_std_17>)
  message(WARNING
    "shacl::variant requiring C++17 because mpark_variant was not found")
endif()

include(GNUInstallDirs)

string(CONCAT prefix
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_include_directories(variant INTERFACE "${prefix}")

add_subdirectory(include/shacl)

install(DIRECTORY include/
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN "*test*" EXCLUDE)

install(FILES
  "${PROJECT_SOURCE_DIR}/.cmake/shacl-config.cmake"
  DESTINATION share/cmake/shacl)

install(TARGETS variant variant-14 EXPORT variantTargets)

install(EXPORT variantTargets
  FILE "shacl-variant-targets.cmake"
  NAMESPACE shacl::
  DESTINATION share/cmake/shacl-variant)

write_basic_package_version_file("shacl-variant-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES
  "${PROJECT_SOURCE_DIR}/cmake/shacl-variant-config.cmake"
  "${PROJECT_BINARY_DIR}/shacl-variant-config-version.cmake"
  DESTINATION share/cmake/shacl-variant)

if(NOT subproject)
  set(CPACK_PACKAGE_VENDOR "Los Alamos National Laboratory")
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
  set(CPACK_PACKAGE_CONTACT "amccartney@lanl.gov")
  include(CPack)
endif()
