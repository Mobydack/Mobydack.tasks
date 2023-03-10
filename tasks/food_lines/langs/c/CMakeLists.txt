add_library(
  food_lines STATIC
  food_lines.c
)

target_include_directories(food_lines PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  food_lines_tests
  food_lines_test.c
)

target_link_libraries(
  food_lines_tests
  food_lines
  Unity
)

add_test(food_lines_test food_lines_tests)
