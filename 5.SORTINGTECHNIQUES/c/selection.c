#include<stdio.h>

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

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
          if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("Sorted array is ::");
    for (int k= 0; k < n; k++)
    {
        printf(" %d ", arr[k]);
    }
    return 0;
    
    }