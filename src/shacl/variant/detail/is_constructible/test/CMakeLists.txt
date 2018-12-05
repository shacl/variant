add_executable(variant.detail.is_constructible.test is_constructible.test.cpp)
target_link_libraries(variant.detail.is_constructible.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.is_constructible.test COMMAND variant.detail.is_constructible.test)
