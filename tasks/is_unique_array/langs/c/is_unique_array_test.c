#include "unity.h"
#include "is_unique_array.h"

void setUp() {};
void tearDown() {}

void test_is_unqiue_arr_should_return_true() {
    int arr[] = { 1, 2, 3, 1 };

    TEST_ASSERT_EQUAL_CHAR(0, is_unique_arr(arr, 4));
}

void test_is_unique_arr_should_return_false() {
    int arr[] = { 1, 2, 3 };

    TEST_ASSERT_EQUAL_CHAR(1, is_unique_arr(arr, 3));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_is_unqiue_arr_should_return_true);
    RUN_TEST(test_is_unique_arr_should_return_false);

    return UNITY_END();
}
