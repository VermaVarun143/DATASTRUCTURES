#include <iostream>
using namespace std;

void mergeSortedLists(int arr1[], int L1, int arr2[], int L2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge both lists until one is exhausted
    while (i < L1 && j < L2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < L1) {
        result[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < L2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7,15};
    int arr2[] = {2, 4, 6, 8};
    int L1 = 6, L2 = 4;
    int result[L1 + L2];

    mergeSortedLists(arr1, L1, arr2, L2, result);

    cout << "Merged Sorted List: ";
    for (int i = 0; i < L1 + L2; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
