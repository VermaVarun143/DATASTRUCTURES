#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *link = NULL;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

// insert at head;

void insertatHead(Node *&head, int data)
{
    Node *node1 = new Node(data);
    node1->link = head;
    head = node1;
}

void insertattail(Node *&tail, int data)
{
    Node *newnode = new Node(data);
    tail->link = newnode;
    tail = newnode;
}
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->link;
    }
}

int main()
{

    Node *newnode = new Node(10);

    Node *head = newnode;
    Node *tail = newnode;

    insertatHead(head, 30);
    insertatHead(head, 50);
    insertatHead(head, 70);

    insertattail(tail, 560);
    insertattail(tail, 730);
    print(head);
    return 0;
}