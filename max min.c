#include <stdio.h>

// Function to find the maximum and minimum elements in an array using divide and conquer
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) { // Base case: If array contains only one element
        *max = *min = arr[low];
    } else if (high - low == 1) { // Base case: If array contains two elements
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    } else { // Recursive case: If array contains more than two elements
        int mid = (low + high) / 2;
        int leftMax, leftMin, rightMax, rightMin;

        // Divide the array into two halves
        findMaxMin(arr, low, mid, &leftMax, &leftMin);
        findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

        // Compare and update the maximum and minimum from left and right halves
        if (leftMax > rightMax)
            *max = leftMax;
        else
            *max = rightMax;

        if (leftMin < rightMin)
            *min = leftMin;
        else
            *min = rightMin;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int max, min;
    findMaxMin(arr, 0, size - 1, &max, &min);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    // Sort the array before performing binary search using QuickSort
    quickSort(arr, 0, size - 1);

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    // Calling the binarySearch function
    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}


