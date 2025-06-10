#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];//dynamic memory allocation for array 1
    int *second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    int p = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[p++];
    }

    // merge
    int index1 = 0;
    int index2 = 0;
    int mainarray = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainarray++] = first[index1++];
        }
        else
        {
            arr[mainarray++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainarray++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainarray++] = second[index2++];
    }
}

void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        // left part sort
        mergesort(arr, start, mid);
        // right part sort
        mergesort(arr, mid + 1, end);
        // merge the 2 arrays
        merge(arr, start, end);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);
cout<<"\n Sorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }

    return 0;
}
