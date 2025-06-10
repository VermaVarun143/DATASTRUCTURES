#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
} *front = NULL, *rear = NULL;

// struct node *rear = NULL;
// struct node *front = NULL;
void enquee(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));
    newnode->data = data;
    if (newnode == NULL)
    {
        cout << "Queue is Overflow";
    }
    else if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
        newnode->link = NULL;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
        newnode->link = NULL;
    }
}
void dequee()
{
    if (front == NULL)
    {
        cout << "NO nodes are present;";
    }
    else if (front == rear)
    {
        int ans=front->data;
        cout<<"\n element popped is :: "<<ans;
        free(front);
        front= NULL;
        rear = NULL;
    }
    else{
         int ans=front->data;
        cout<<"\n element popped is :: "<<ans;
        struct node*temp;
        temp=front;
        front=front->link;
        free(temp);
    }
}
void display(){
    if(front==NULL){
        cout<<"QUeue IS Empty";

    }
    else{
        struct node*temp=front;
        cout<<"Queue ELement";
        while(temp!=NULL){
            cout<<temp->data<<"   ";
            temp=temp->link;
        }
    }
}

int main()
{
    cout << "1.PUSH\n 2.POP \n3.FRONT\n4.EXIT\n5.DISPLAY ";
    char choice;

    do
    {
        cout << "\nEnter Your Choice::";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "ENter THE VAlue :: ";
            int n;
            cin >> n;
            enquee(n);
            break;
        case '2':
            dequee();
            break;
        case '3':
            // front1();
            break;
        case '4':
            exit(1);
            break;
        case '5':

          display();

            break;
        }
    } while (choice != 4);
}
