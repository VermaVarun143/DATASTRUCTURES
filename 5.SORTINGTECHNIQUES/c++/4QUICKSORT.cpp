
//hoare partition method
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int count = 0;

    // less than number then pivot
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotindex = l + count;
    swap(arr[pivotindex], arr[l]);

    // left and right part

    int i = l;
    int j = r;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j++;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotindex;
}

void quicksort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    else
    {
        // partition
        int p = partition(arr, left, right);

        // leftpart to sort
        quicksort(arr, left, p - 1);

        // right to sort

        quicksort(arr, p + 1, right);
    }
}

int main()
{
    int n;
    cout << "ENter the NUmber of elements";
    cin >> n;
    int arr[n];
    cout << "Enter the elements";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0, end = n - 1;
    quicksort(arr, start, end);

    cout << "Sorted array";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
