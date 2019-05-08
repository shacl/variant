add_executable(shacl.variant.detail.alternatives_of.test
  alternatives_of.test.cpp)
target_link_libraries(shacl.variant.detail.alternatives_of.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.alternatives_of.test COMMAND
  shacl.variant.detail.alternatives_of.test)
