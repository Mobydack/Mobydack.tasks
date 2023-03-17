#include "unity.h"
#include "snowflakes.h"

void setUp() {};
void tearDown() {}

void test_is_contains_duplicates_returns_true_if_array_contains_duplicates() {
    int snowflakes[][6] = { { 1, 2, 3, 4, 5, 6}, { 1, 2, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5, 6 } };

    char result = is_contains_duplicates(snowflakes, 3);

    TEST_ASSERT_EQUAL_CHAR(1, result);
}

void test_is_contains_duplicates_returns_false_if_array_doesnt_contains_duplicates() {
    int snowflakes[][6] = { { 1, 2, 3, 4, 5, 6 }, { 1, 3, 3, 4, 5, 6 } };

    char result = is_contains_duplicates(snowflakes, 2);

    TEST_ASSERT_EQUAL_CHAR(0, result);
}

void test_is_contains_duplicates_returns_false_if_snowflakes_have_equals_sum() {
    int snowflakes[][6] = { { 2, 2, 2, 2, 2, 2 }, { 1, 1, 1, 1, 1, 7 } };

    char result = is_contains_duplicates(snowflakes, 2);

    TEST_ASSERT_EQUAL_CHAR(0, result);
}

void test_is_contains_duplicates_returns_true_with_right_direction_equals_pairs() {
    int snowflakes[][6] = { { 1, 2, 3, 4, 5, 6 }, { 4, 5, 6, 1, 2, 3 } };

    char result = is_contains_duplicates(snowflakes, 2);

    TEST_ASSERT_EQUAL_CHAR(0, result);
}

void test_is_contains_duplicates_returns_true_with_left_direction_equals_pairs() {
    int snowflakes[][6] = { { 3, 2, 1, 6, 5, 4 }, { 1, 2, 3, 4, 5, 6 } };

    char result = is_contains_duplicates(snowflakes, 2);

    TEST_ASSERT_EQUAL_CHAR(0, result);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_is_contains_duplicates_returns_true_if_array_contains_duplicates);
    RUN_TEST(test_is_contains_duplicates_returns_false_if_array_doesnt_contains_duplicates);
    RUN_TEST(test_is_contains_duplicates_returns_false_if_snowflakes_have_equals_sum);
    RUN_TEST(test_is_contains_duplicates_returns_true_with_right_direction_equals_pairs);
    RUN_TEST(test_is_contains_duplicates_returns_true_with_left_direction_equals_pairs);

    return UNITY_END();
}
