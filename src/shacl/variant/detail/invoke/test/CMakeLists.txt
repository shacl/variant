add_executable(variant.detail.invoke.test invoke.test.cpp)
target_link_libraries(variant.detail.invoke.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.invoke.test COMMAND variant.detail.invoke.test)
