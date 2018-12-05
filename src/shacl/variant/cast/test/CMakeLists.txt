add_executable(variant.cast.test cast.test.cpp)
target_link_libraries(variant.cast.test PUBLIC shacl::variant::testing)
add_test(NAME variant.cast.test COMMAND variant.cast.test)
