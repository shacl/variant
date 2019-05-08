add_executable(shacl.variant.detail.decay.test decay.test.cpp)
target_link_libraries(shacl.variant.detail.decay.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.decay.test COMMAND
  shacl.variant.detail.decay.test)
