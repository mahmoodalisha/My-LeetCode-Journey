#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) 
        return -1; // Key not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) 
        return mid; // Key found at index mid
    else if (arr[mid] > key) 
        return binarySearch(arr, low, mid - 1, key); // Search in the left half
    else 
        return binarySearch(arr, mid + 1, high, key); // Search in the right half
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
