add_executable(shacl.variant.detail.argument_type_product.test
  argument_type_product.test.cpp)
target_link_libraries(shacl.variant.detail.argument_type_product.test PUBLIC
  shacl::variant::testing)
add_test(NAME shacl.variant.detail.argument_type_product.test COMMAND
  shacl.variant.detail.argument_type_product.test)
