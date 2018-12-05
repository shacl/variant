add_executable(variant.bind.test bind.test.cpp)
target_include_directories(variant.bind.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(variant.bind.test PUBLIC shacl::variant::testing)
add_test(NAME variant.bind.test COMMAND variant.bind.test)
