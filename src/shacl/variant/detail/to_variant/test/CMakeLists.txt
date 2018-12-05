add_executable(variant.detail.to_variant.test to_variant.test.cpp)
target_link_libraries(variant.detail.to_variant.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.to_variant.test COMMAND variant.detail.to_variant.test)
