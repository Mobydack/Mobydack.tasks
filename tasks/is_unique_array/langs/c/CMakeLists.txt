add_library(
  is_unique_array STATIC
  is_unique_array.c
)

target_include_directories(is_unique_array PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  is_unique_array_tests
  is_unique_array_test.c
)

target_link_libraries(
  is_unique_array_tests
  is_unique_array
  Unity
)

add_test(is_unique_array_test is_unique_array_tests)
