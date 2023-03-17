add_library(
  snowflakes STATIC
  snowflakes.c
)

target_include_directories(snowflakes PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  snowflakes_tests
  snowflakes_test.c
)

target_link_libraries(
  snowflakes_tests
  snowflakes
  Unity
)

add_test(snowflakes_test snowflakes_tests)
