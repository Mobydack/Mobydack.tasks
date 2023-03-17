#include <stdlib.h>
#define MAX_SNOWFLAKES 100000

const int SNOWFLAKE_SIZE = 6;

enum Direction { Left, Right };

typedef struct SnowflakeNode {
    int *snowflake_arr;
    struct SnowflakeNode *next;
} SnowflakeNode;


char identical_by_direction(int arr_1[], int length_1, int arr_2[], int length_2, int start, enum Direction direction) {
    if (length_1 != length_2) {
        return 0;
    }

    int direction_multiplicator = -1;

    if (direction == Right) {
        direction_multiplicator = 1;
    }

    for (int index = 0; index < length_1; index += 1) {
        int normalized_start = start - 1;

        if (normalized_start < 0) {
            normalized_start = 0;
        }

        int offset = normalized_start + index * direction_multiplicator;

        if (offset >= length_1) {
            offset = 0;
        } else if (offset < 0) {
            offset = index + length_1 - 1;
        }

        if (arr_1[index] != arr_2[offset]) {
            return 0;
        }
    }

    return 1;
}

SnowflakeNode* createSnowflakeNode(int *snowflake_arr) {
    SnowflakeNode *node = malloc(sizeof(SnowflakeNode));

    if (node == NULL) {
        exit(0);
    }

    node -> snowflake_arr = snowflake_arr;
    node -> next = NULL;

    return node;
}

int create_hash_sum(int arr[], int length) {
    int sum = 0;

    for (int i = 0; i < length; i += 1) {
        sum += arr[i];
    }

    return sum;
}

char is_equal_nodes(int *snowflake_1, int *snowflake_2) {
    int i;

    for (i = 0; i < SNOWFLAKE_SIZE; i += 1) {
        if (identical_by_direction(snowflake_1, SNOWFLAKE_SIZE, snowflake_2, SNOWFLAKE_SIZE, i, Right)) {
            return 1;
        }

        if (identical_by_direction(snowflake_1, SNOWFLAKE_SIZE, snowflake_2, SNOWFLAKE_SIZE, i, Left)) {
            return 1;
        }
    }

    return 0;
}

char identify_identical(SnowflakeNode *node) {
    SnowflakeNode *current_node = node;
    SnowflakeNode *next_node;

    while (current_node != NULL) {
        next_node = current_node -> next;

        while (next_node != NULL) {
            if (is_equal_nodes(current_node -> snowflake_arr, next_node -> snowflake_arr)) {
                return 1;
            }

            next_node = next_node -> next;
        }

        current_node = next_node;
    }

    return 0;
}

char is_contains_duplicates(int arr[][SNOWFLAKE_SIZE], int length) {
    SnowflakeNode *nodes[100000] = { NULL };
    SnowflakeNode *node;
    int i, hash_sum;

    for (i = 0; i < length; i += 1) {
        node = createSnowflakeNode(arr[i]);
        hash_sum = create_hash_sum(node -> snowflake_arr, SNOWFLAKE_SIZE) % length;

        node -> next = nodes[hash_sum];
        nodes[hash_sum] = node;
    }

    for (i = 0; i < length; i += 1) {
        node = nodes[i];

        if (node == NULL || node -> next == NULL) {
            continue;
        }

        char is_contain_identical = identify_identical(node);

        if (is_contain_identical == 1) {
            return 1;
        }
    }

    return 0;
}
