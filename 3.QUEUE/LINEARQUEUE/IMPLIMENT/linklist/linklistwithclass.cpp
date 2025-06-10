#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link = nullptr;
    node *front = nullptr, *rear = nullptr;

    void enquee()
    {
        node *newnode = new node;
        int val;
        cout << "ENter Value";
        cin >> val;
        newnode->data = val;
        if (front == nullptr && rear == nullptr)
        {
            front = newnode;
            rear = newnode;
            newnode->link = nullptr;
        }
        else
        {
            rear->link = newnode;
            rear = newnode;
            newnode->link = nullptr;
        }
    }
    void dequee()
    {
        if (front == nullptr && rear == nullptr)
        {
            cout << "LInk list Is Empty";
        }
        else if (front == rear)
        {
            int ans=front->data;
            free(front);
            front = nullptr;
            rear = nullptr;
            cout<<"\nElement dequeed is: "<<ans;
        }
        else
        {
            int ans=front->data;
            node *temp;
            temp = front;
            front = front->link;
            free(temp);
             cout<<"\nElement dequeed is: "<<ans;
        }
    }
    void display()
    {
        node *temp;
        temp = front;
        cout << "Link List Element  :: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
};
int main()
{
    node obj;
    char choice;

    cout << "\n 1. Enquee\n2.Dequee\n3.Display";
    while (choice != 4)
    {
        cout << "\nEnter CHoice:";
        cin >> choice;
        switch (choice)
        {
        case '1':
            obj.enquee();
            break;
        case '2':
            obj.dequee();
            break;
        case '3':
            obj.display();
            break;
        case '4':
            return 0;
            break;
        }
    }
    return 0;
}