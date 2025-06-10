#include <stdio.h>

// Function to perform the Lomuto partition
int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // Choose the rightmost element as pivot
    int i = left - 1;        // Pointer for the smaller element

    for (int j = left; j < right; j++) {  // Loop through the array
        if (arr[j] < pivot) {              // If current element is less than pivot
            i++;                           // Increment the smaller element index
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[right] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;  // Return the index of the pivot
}

// Function to perform Quick Sort
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, left, right);

        // Recursively sort elements before and after partition
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
}

// Main function to run the Quick Sort
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);  // Call Quick Sort

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

