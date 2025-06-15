#include <stdio.h>

void shift_left(int *arr, int start_index, int size) {
    for (int i = start_index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // printf("array: ");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
}

int remove_duplicates_from_array(int *arr, int size) {

    if (size < 2) return size;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            shift_left(arr, i, size);
            size--;
            i--;
        }
    }
    return size;
}
