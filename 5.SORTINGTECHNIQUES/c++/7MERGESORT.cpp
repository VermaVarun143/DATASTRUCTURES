#include <iostream>
using namespace std;

/* Function to merge two subarrays of a[]:
   - First subarray is a[beg..mid]
   - Second subarray is a[mid+1..end]
*/
void merge(int a[], int beg, int mid, int end)
{
    // Step 1: Calculate the sizes of the two subarrays to merge
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    // Step 2: Create temporary arrays to hold the elements of the subarrays
    int LeftArray[n1], RightArray[n2];

    // Step 3: Copy data into the temporary arrays
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i]; // Elements from beg to mid go to LeftArray
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j]; // Elements from mid+1 to end go to RightArray

    // Step 4: Initialize indices for iteration
    int i = 0;   // Initial index of LeftArray
    int j = 0;   // Initial index of RightArray
    int k = beg; // Initial index for merged array (a[])

    // Step 5: Merge the two subarrays back into a[]
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j]) // Choose the smaller element from LeftArray or RightArray
        {
            a[k] = LeftArray[i]; // Place LeftArray[i] into a[k]
            i++;                 // Move to next element in LeftArray
        }
        else
        {
            a[k] = RightArray[j]; // Place RightArray[j] into a[k]
            j++;                  // Move to next element in RightArray
        }
        k++; // Move to the next position in a[]
    }

    // Step 6: Copy any remaining elements of LeftArray (if any)
    while (i < n1)
    {
        a[k] = LeftArray[i]; // Copy the rest of LeftArray into a
        i++;
        k++;
    }

    // Step 7: Copy any remaining elements of RightArray (if any)
    while (j < n2)
    {
        a[k] = RightArray[j]; // Copy the rest of RightArray into a
        j++;
        k++;
    }
}

// Function to perform merge sort on array a[]
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2; // Calculate the middle index

        mergeSort(a, beg, mid);     // Sort the first half
        mergeSort(a, mid + 1, end); // Sort the second half
        merge(a, beg, mid, end);    // Merge the sorted halves
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Perform merge sort on the array
    mergeSort(a, 0, n - 1);

    // Display the sorted array
    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
