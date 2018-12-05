add_executable(variant.detail.alternatives_of.test alternatives_of.test.cpp)
target_link_libraries(variant.detail.alternatives_of.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.alternatives_of.test COMMAND variant.detail.alternatives_of.test)
