#include <iostream>
using namespace std;
int main()
{
    int arr[50], n, i, j, swap;
    cout << "Enter Number ofElements";
    cin >> n;
    cout << "Enter Elements";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int revarray[n];
    for(int i=0;i<n;i++){
        revarray[i]=arr[n-1-i];
    }

    cout<<"\n\n reverse array::  ";
    for(int i=0;i<n;i++){
        cout<<revarray[i]<<"  ";
    }
    return 0;
}