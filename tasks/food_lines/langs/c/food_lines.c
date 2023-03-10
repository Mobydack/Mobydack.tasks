int find_min_value_index(int arr[], int length) {
    int minimal_value_index = 0;

    for (int index = 1; index < length; index += 1) {
        if (arr[index] < arr[minimal_value_index]) {
            minimal_value_index = index;
        }
    }

    return minimal_value_index;
}

void addition_to_array(int distribution_number, int arr[], int length) {
    for (int number = 0; number < distribution_number; number += 1) {
        int min_value_index = find_min_value_index(arr, length);

        arr[min_value_index] += 1;
    }
}
