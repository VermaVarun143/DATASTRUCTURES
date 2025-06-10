#include <iostream>
using namespace std;

// Partition function using Lomuto partition scheme
int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // Step 1: Choose the pivot as the rightmost element
    int i = left - 1;        // Step 2: Initialize i to track elements less than pivot

    for (int j = left; j < right; j++) {   // Step 3: Loop through elements from 'left' to 'right - 1'
        if (arr[j] < pivot) {              // Step 4: Check if element is less than pivot
            i++;                           // Step 5: Move boundary up
            swap(arr[i], arr[j]);          // Step 6: Swap element at j with element at i
        }
    }
    swap(arr[i + 1], arr[right]);          // Step 7: Place pivot in its correct position
    return i + 1;                          // Return pivot's final index
}


// Quick Sort function
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right); // Partition the array
        quicksort(arr, left, p - 1);         // Sort left subarray
        quicksort(arr, p + 1, right);        // Sort right subarray
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quicksort(arr, 0, n - 1); // Call Quick Sort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
