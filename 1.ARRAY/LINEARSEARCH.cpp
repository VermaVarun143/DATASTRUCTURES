#include <iostream>
using namespace std;
int main()
{
    int arr[20], n, search, i;
    cout << "Enter the number of elements :: ";
    cin >> n;
    cout << "\nEnter the Elements of array :: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nYour Array :: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter the Number to Be Searched :: ";
    cin >> search;

    for (i = 0; i < n; i++)
    {
        if (search == arr[i])
        {
            cout << "\nElement Is Found ::" << search << endl
                 << "at index :: " << i;
            break;
        }
    }
    if (i == n)
    {

        cout << "\nElement IS not Found";
    }

    return 0;
}