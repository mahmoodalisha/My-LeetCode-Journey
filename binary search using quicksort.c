#include <stdio.h>


int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearch(arr, mid + 1, high, key);
        else
            return binarySearch(arr, low, mid - 1, key);
    }
    return -1; // If element is not present in the array
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); //i starts at low - 1 to indicate that no elements smaller than the pivot have been placed in the "smaller-than-pivot" section yet.

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  //checks if the current element (arr[j]) is smaller than the pivot value.
            i++;  //i keeps track of the elements smaller than the pivot
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
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

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

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
