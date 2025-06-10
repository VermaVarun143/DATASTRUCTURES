#include <iostream>
using namespace std;
int size, front, rear;
//create a array
int *arr;
class queue
{

public:
    queue()
    {
        front = rear = 0;
        size = 5;

        //giving space to arraydynamically
        arr = new int[size];
    }

    void enquee()
    {
        if (rear == size)
        {
            cout << "QUEUE IS OVERFLOW";
        }
        else
        {
            int n;
            cout << "Enter THE ELement";
            cin >> n;
            arr[rear] = n;
            rear++;
        }
    }

    int dequee()
    {
        if (front == rear)
        {
            cout << "Stack IS Empty";
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = 0;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int isEmpty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
            return 0;
    }

    int front1()
    {
        if (rear == front)
        {
            cout << "Staack is Empty";
        }
        else
        {
            cout << arr[front];
        }
    }
};

int main()
{
    cout << "1.PUSH\n 2.POP \n3.FRONT\n4.EXIT\n5.DISPLAY ";
    char choice;
    queue st;
    do
    {
        cout << "\nEnter Your Choice::";
        cin >> choice;
        switch (choice)
        {
        case '1':

            st.enquee();
            break;
        case '2':
            st.dequee();
            break;
        case '3':
            st.front1();
            break;
        case '4':
            exit(1);
            break;
        case '5':
            cout << "\n\nSTACK::  ";
          for( int i=front;i<rear;i++){
            cout<<arr[i]<<" " ;
          }

           
            break;
        }
    } while (choice != 4);
}