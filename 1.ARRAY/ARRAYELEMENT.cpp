#include <iostream>
using namespace std;
int main()
{
    int a[] = {2, 5, 4, 3, 6}, pos, num, i;
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Array of Elements =";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << "\nEnter Element To Insert";
    cin >> num;
    cout << "\nEnter Position to insert";
    cin >> pos;

    if (pos > n || pos < 0)
    {
        cout << "Invalid Position";
    }
    else
    {
       for(i=n;i>=pos;i--){
        a[i]=a[i-1];
        
       }
       a[pos]=num;
        // for (i = n - 1; i >= pos; i--)
        // {
        //     a[i + 1] = a[i];
        // }
        // a[pos] = num;
        cout<<"\n new Array:: ";
for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    
    return 0;
}
