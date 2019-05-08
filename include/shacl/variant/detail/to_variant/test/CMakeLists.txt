add_executable(shacl.variant.detail.to_variant.test to_variant.test.cpp)
target_link_libraries(shacl.variant.detail.to_variant.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.to_variant.test COMMAND
  shacl.variant.detail.to_variant.test)
