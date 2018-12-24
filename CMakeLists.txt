cmake_minimum_required(VERSION 3.8)

set(subproject OFF)
if(DEFINED PROJECT_NAME)
  set(subproject ON)
endif()

project(variant VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/.cmake")
include(CTest)
include(CMakeDependentOption)
include(Git/Submodule/Packages)

CMAKE_DEPENDENT_OPTION(variant.tests
  "Build the variant tests and integrate with ctest"
  ON "BUILD_TESTING; NOT subproject" OFF)

add_library(variant INTERFACE)
add_library(shacl::variant ALIAS variant)

find_package(shacl REQUIRED COMPONENTS trait ebo)
find_package(mpark_variant REQUIRED)

find_package(Boost 1.61)
if(NOT Boost_FOUND)
  find_package(hana REQUIRED)
  add_library(Boost::boost ALIAS hana)
endif()

target_link_libraries(variant INTERFACE
  shacl::trait
  shacl::ebo
  Boost::boost
  $<$<VERSION_LESS:$<TARGET_PROPERTY:CXX_STANDARD>,17>:mpark_variant>)

target_include_directories(variant INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>)

target_compile_features(variant INTERFACE cxx_std_14)

if(variant.tests)
  include(Warnings)
  include(Sanitizers)

  find_package(Catch2)

  set(CMAKE_CXX_EXTENSIONS OFF)

  add_library(testing INTERFACE)
  add_library(shacl::variant::testing ALIAS testing)

  set_target_properties(testing PROPERTIES
    INTERFACE_WARN_ALL ON
    INTERFACE_WARN_ERROR ON)

  set_property(TARGET testing APPEND PROPERTY COMPATIBLE_INTERFACE_BOOL
    WARN_ALL WARN_ERROR)

  target_link_libraries(testing INTERFACE
    Catch2::Catch2
    Warnings::Warnings_CXX
    shacl::sanitizers_CXX
    shacl::variant)
endif()

add_subdirectory(src/shacl)

install(TARGETS variant EXPORT variantTargets)

install(EXPORT variantTargets
  FILE variantTargets.cmake
  NAMESPACE shacl::
  DESTINATION share/cmake/shacl/variant)

install(DIRECTORY src/ DESTINATION include
  PATTERN "*test*" EXCLUDE
  PATTERN "*CMakeLists.txt" EXCLUDE
  PATTERN "*~" EXCLUDE)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("variantConfigVersion.cmake"
  VERSION ${variant_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES
  "${variant_SOURCE_DIR}/.cmake/variantConfig.cmake"
  "${variant_BINARY_DIR}/variantConfigVersion.cmake"
  DESTINATION share/cmake/shacl/variant)

install(FILES
  "${variant_SOURCE_DIR}/.cmake/shaclConfig.cmake"
  DESTINATION share/cmake/shacl)

if(NOT subproject)
  include(InstallRequiredSystemLibraries)
  set(CPACK_PACKAGE_VENDOR "Los Alamos National Laboratory")
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
  set(CMAKE_PROJECT_HOMEPAGE_URL "https://xcp-stash.lanl.gov/projects/SCL/repos/variant")
  set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Utilities for (and optional C++14 backport of) std::variant")
  set(CPACK_PACKAGE_CONTACT "amccartney@lanl.gov")
  include(CPack)
endif()
