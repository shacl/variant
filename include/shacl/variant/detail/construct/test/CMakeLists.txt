add_executable(shacl.variant.detail.construct.test construct.test.cpp)
target_link_libraries(shacl.variant.detail.construct.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.construct.test COMMAND
  shacl.variant.detail.construct.test)
