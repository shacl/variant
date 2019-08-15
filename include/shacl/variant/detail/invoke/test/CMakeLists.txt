add_executable(shacl.variant.detail.invoke.test invoke.test.cpp)
target_link_libraries(shacl.variant.detail.invoke.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.invoke.test COMMAND
  shacl.variant.detail.invoke.test)
