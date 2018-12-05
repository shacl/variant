add_executable(variant.detail.sum.test sum.test.cpp)
target_link_libraries(variant.detail.sum.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.sum.test COMMAND variant.detail.sum.test)
