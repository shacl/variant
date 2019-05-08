add_executable(shacl.variant.detail.possible_result_types_of.test
  possible_result_types_of.test.cpp)
target_link_libraries(shacl.variant.detail.possible_result_types_of.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.possible_result_types_of.test COMMAND
  shacl.variant.detail.possible_result_types_of.test)
