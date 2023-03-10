#include <unity.h>
#include <food_lines.h>

void setUp() {}

void tearDown() {}

void test_find_min_value_index_get_minimal_value_index() {
  int arr[] = { 2, 4, 5, 0, 1 };

  int result = find_min_value_index(arr, 5);

  TEST_ASSERT_EQUAL_INT(3, result);
}

void test_find_min_value_index_get_minimal_value_index_with_cut_length() {
  int arr[] = { 2, 4, 5, 0, 1 };

  int result = find_min_value_index(arr, 3);

  TEST_ASSERT_EQUAL_INT(0, result);
}

void test_addition_value_to_array_correct_increment_all_values() {
  int distribution_number = 4;
  int arr[] = { 2, 4, 5 };
  int expected_arr[] = { 5, 5, 5 };

  addition_to_array(distribution_number, arr, 3);

  TEST_ASSERT_EQUAL_INT_ARRAY(expected_arr, arr, 3);
}

void test_addition_value_to_array_didnt_increment_with_zero_distrbution_number() {
  int distribution_number = 4;
  int arr[] = { 2, 4, 5 };
  int expected_arr[] = { 5, 5, 5 };

  addition_to_array(distribution_number, arr, 3);

  TEST_ASSERT_EQUAL_INT_ARRAY(expected_arr, arr, 3);
}


int main() {
  UNITY_BEGIN();

  // start units for find_min_value_index
  RUN_TEST(test_find_min_value_index_get_minimal_value_index);
  RUN_TEST(test_find_min_value_index_get_minimal_value_index_with_cut_length);
  // end units for find_min_value_

  // start units for addition_to_array
  RUN_TEST(test_addition_value_to_array_correct_increment_all_values);
  RUN_TEST(test_addition_value_to_array_didnt_increment_with_zero_distrbution_number);
  // end units for addition_to_array

  return UNITY_END();
}
