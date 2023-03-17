char is_unique_arr(int arr[], int length) {
    for (int i = 0; i < length; i += 1) {
        for (int j = i + 1; j < length; j += 1) {
            if (arr[i] == arr[j]) {
                return 0;
            }
        }
    }

    return 1;
}
