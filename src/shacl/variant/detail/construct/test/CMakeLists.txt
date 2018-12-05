add_executable(variant.detail.construct.test construct.test.cpp)
target_link_libraries(variant.detail.construct.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.construct.test COMMAND variant.detail.construct.test)
