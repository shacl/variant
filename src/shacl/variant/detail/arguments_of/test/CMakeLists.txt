add_executable(variant.detail.arguments_of.test arguments_of.test.cpp)
target_link_libraries(variant.detail.arguments_of.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.arguments_of.test COMMAND variant.detail.arguments_of.test)
