#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *link;
};
struct Node* top = NULL;

void push(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        cout << "STack IS Overflow";
    }
    newNode->data = data;
    newNode->link = NULL;
    newNode->link = top;

    top = newNode;
}
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    struct node *temp;
    temp = (struct node *)top;

    if (top == NULL)
    {
        cout << "Stack IS Empty";
        // exit(1);
    }

    cout << "The pop element is " << top->data << endl;
    top = top->link;
    free(temp);
    temp = NULL;
}
// void pop() {
//    if(top==NULL)
//    cout<<"Stack Underflow"<<endl;
//    else {
//       cout<<"The popped element is "<< top->data <<endl;
//       top = top->link;
//    }
// }

void display()
{
    struct Node *ptr;
    ptr = (struct Node *)top;
    if (top == NULL)

        cout << "stack is empty";
    else
    {

        cout << "Stack elements are: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
    }
    cout << endl;
}
void peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty";
    }
    else
    {
        cout << "\nTOP:: " << top->data;
    }
}
int main()
{
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) TOp" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            cout << "Exit" << endl;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 5);
    return 0;
}
