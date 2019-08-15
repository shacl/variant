add_executable(shacl.variant.detail.is_constructible.test
  is_constructible.test.cpp)
target_link_libraries(shacl.variant.detail.is_constructible.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.is_constructible.test COMMAND
  shacl.variant.detail.is_constructible.test)
