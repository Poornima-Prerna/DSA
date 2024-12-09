#include <stdio.h>

int missing_number(int arr[], int n) {
    int sum_of_all = (n * (n + 1)) / 2; // Sum of 0 to n
    int sum_of_arr = 0;
    for (int i = 0; i < n; i++) {
        sum_of_arr += arr[i];
    }
    return sum_of_all - sum_of_arr;
}

int main() {
    int arr[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Missing number: %d\n", missing_number(arr, n));

    return 0;
    }