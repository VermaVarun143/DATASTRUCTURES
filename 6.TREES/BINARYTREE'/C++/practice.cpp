#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node *create()
{
    node *temp;
    cout << "\nEnter 0 for exit,and 1for create a node\n";
    int choice;
    cin >> choice;
    if (choice == 0)
    {
        return nullptr;
    }
    else
    {
        temp=new node;
        int data;
        cout << "Enter the data";
        cin>>data;
        temp->data = data;

        cout << "Enter data for left node of " << data << "node";
        temp->left = create();

        cout << "Enter data for right node of " << data << "node";
        temp->right = create();

        return temp;
    }
}
int main()
{
    node *root;
    root = create();
    return 0;
}