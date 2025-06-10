#include <iostream>
#include <cstdlib>
#include <ctime>
// Function to swap two elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Function to partition the array
int partitionLeft(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
            
        }
    }
    swap(arr, i+1, high);
    return i+1;
}
// Function to perform random partition
int partitionRight(int arr[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low);
    swap(arr, r, high);
    return partitionLeft(arr, low, high);
}
// Recursive function for quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionRight(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
// Driver code
int main() {
    int arr[] = {6, 4, 12, 8, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}