#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link = nullptr, *top = nullptr;

    void push()
    {
        int num;
        cout << "\nENter NUmber";
        cin >> num;
        node *newnode = new node;
        newnode->data = num;
        if (newnode == nullptr)
        {
            cout << "Cant INserted";
        }
        else if (top == nullptr)
        {
            top = newnode;
            newnode->link = nullptr;
        }
        else
        {
            newnode->link = top;
            top = newnode;
        }
    }
    void pop()
    {
        node *temp;
        temp = top;
        if (temp == nullptr)
        {
            cout << "NO nodes are present ";
        }
        else
        {
            top = temp->link;
            free(temp);
        }
    }
    int empty()
    {
        if (top == nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        node *temp;
        temp = top;
        if (empty())
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << "\nStack Elements::   ";
            while (temp != nullptr)
            {
                cout << temp->data << "  ";
                temp = temp->link;
            }
        }
    }
};

int main()
{
    node obj;
    cout << "\n1. PUSH \n2.POP\n3.Display";
    char choice;

    do
    {
        cout << "\nEnter YOur CHoice";
        cin >> choice;
        switch (choice)
        {
        case '1':

            obj.push();
            break;
        case '2':
            obj.pop();
            break;
        case '3':
            obj.display();
            break;
        default:
            cout << "ENter Valid Input";
        }
    } while (choice != 4);
    return 0;
}