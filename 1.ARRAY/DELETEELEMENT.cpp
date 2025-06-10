#include <iostream>
using namespace std;
int main()
{
    int a[20], n, pos, i, length;
    cout << "Enter the number of Elements:: ";
    cin >> n;
    cout << "\nEnter the Elements of an Array:: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "your array::  ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n Enter Your Position to delete:: ";
cin>>pos;

if(pos>n || pos<0){
    cout<<"invalid choice";
}
else{
    for(i=pos;i<n;i++){
    a[i]=a[i+1];
}
cout << " array::  ";
    for (i = 0; i < n-1; i++)
    {
        cout << a[i] << " ";
    }
}


    return 0;
}