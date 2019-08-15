add_executable(shacl.variant.cast.test cast.test.cpp)
target_link_libraries(shacl.variant.cast.test PUBLIC shacl::variant::testing)
add_test(NAME shacl.variant.cast.test COMMAND shacl.variant.cast.test)
