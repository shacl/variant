add_executable(variant.map.test map.test.cpp)
target_include_directories(variant.map.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(variant.map.test PUBLIC shacl::variant::testing)
add_test(NAME variant.map.test COMMAND variant.map.test)
