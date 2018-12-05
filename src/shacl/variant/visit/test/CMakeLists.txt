add_executable(variant.visit.test visit.test.cpp Result.test.cpp)
target_include_directories(variant.visit.test
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(variant.visit.test PUBLIC shacl::variant::testing)
add_test(NAME variant.visit.test COMMAND variant.visit.test)
