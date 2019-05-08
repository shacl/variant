add_executable(shacl.variant.visit.test visit.test.cpp Result.test.cpp)
target_include_directories(shacl.variant.visit.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(shacl.variant.visit.test PUBLIC shacl::variant::testing)
add_test(NAME shacl.variant.visit.test COMMAND shacl.variant.visit.test)
