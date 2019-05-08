add_executable(shacl.variant.map.test map.test.cpp)
target_include_directories(shacl.variant.map.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(shacl.variant.map.test PUBLIC shacl::variant::testing)
add_test(NAME shacl.variant.map.test COMMAND shacl.variant.map.test)
