#include <stdio.h>

int findMin(int arr[], int low, int high) {
    // Base cases
    if (low == high) {
        return arr[low];
    }
    if (high == low + 1) {
        return arr[low] < arr[high] ? arr[low] : arr[high];
    }

    int mid = low + (high - low) / 2;

    // If mid itself is the minimum element
    if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]) {
        return arr[mid];
    }

    // If left half is sorted, the minimum element is in the right half
    if (arr[mid] > arr[high]) {
        return findMin(arr, mid + 1, high);
    }

    // If right half is sorted, the minimum element is in the left half
    return findMin(arr, low, mid - 1);
}

int main() {
    int arr[] = {5, 6, 7, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = findMin(arr, 0, n - 1);

    printf("The minimum element is %d\n", min);

    return 0;
}
