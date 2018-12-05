add_executable(variant.detail.possible_result_types_of.test possible_result_types_of.test.cpp)
target_link_libraries(variant.detail.possible_result_types_of.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.possible_result_types_of.test COMMAND variant.detail.possible_result_types_of.test)
