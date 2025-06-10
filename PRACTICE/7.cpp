#include <iostream >
#include <stddef.h>
using namespace std;

int main()
{
    int arr[] = {10, 5, 6, 7, 8, 3, 5};
    int size = sizeof(arr) / sizeof(arr[1]);
    int size2 = sizeof(arr);
    cout << "size" << size;
    cout << endl << size2;
}
