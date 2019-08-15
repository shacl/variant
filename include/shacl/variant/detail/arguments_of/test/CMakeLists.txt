add_executable(shacl.variant.detail.arguments_of.test arguments_of.test.cpp)
target_link_libraries(shacl.variant.detail.arguments_of.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.arguments_of.test COMMAND
  shacl.variant.detail.arguments_of.test)
