add_executable(shacl.variant.detail.sum.test sum.test.cpp)
target_link_libraries(shacl.variant.detail.sum.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.sum.test COMMAND
  shacl.variant.detail.sum.test)
