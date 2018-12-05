add_executable(variant.detail.decay.test decay.test.cpp)
target_link_libraries(variant.detail.decay.test PUBLIC shacl::variant::testing)
add_test(NAME variant.detail.decay.test COMMAND variant.detail.decay.test)
