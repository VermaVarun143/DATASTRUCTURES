#include <iostream>
using namespace std;
int main()
{
    int i, arr[50], j, search, n, temp;
    cout << "Enter the Number OF Elements";
    cin >> n;
    cout << "\n Enter Elements of Array";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nYour Array:: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // Bubble sort
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\n Array IN Increasing Order :: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // binary search
    cout << "Enter the element to Search";
    cin >> search;

    int first = 0, last, middle,f=0;
    
    last = n - 1;
   
    while (first <= last)
    { middle = (first + last) / 2;
        if (search > arr[middle])
        {
            first = middle+ 1;
        }
        else if (search==arr[middle])
        {
            cout << "Element is found ::"<<arr[middle];
            f=1;
            break;
           
        }
        else if(search<arr[middle])
        {
            last = middle - 1;
        
           
        }
    }
if(f==0){
    cout<<"Element is not found";
}
    return 0;
}