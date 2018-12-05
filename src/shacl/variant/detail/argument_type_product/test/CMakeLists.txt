add_executable(variant.detail.argument_type_product.test argument_type_product.test.cpp)
target_link_libraries(variant.detail.argument_type_product.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.argument_type_product.test COMMAND variant.detail.argument_type_product.test)
