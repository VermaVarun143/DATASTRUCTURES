#include <stdio.h>

int main()
{
    int n;
    printf("Enter The number of elements:: ");
    scanf("%d", &n);
    int arr[n];
    printf("ENter The Elements:: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key <= arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }

    printf("Sorted array is ::");
    for (int k= 0; k < n; k++)
    {
        printf(" %d ", arr[k]);
    }
    return 0;
}