add_executable(shacl.variant.bind.test bind.test.cpp)
target_include_directories(shacl.variant.bind.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(shacl.variant.bind.test PUBLIC shacl::variant::testing)
add_test(NAME shacl.variant.bind.test COMMAND shacl.variant.bind.test)
