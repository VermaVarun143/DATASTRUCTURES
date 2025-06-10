#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *root, int data)
{

    if (root == nullptr)
    {
        root = new node;
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
// Preorder traversal: Root -> Left -> Right
void preorder(node *root)
{
    if (root == nullptr)
    {
       
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = nullptr;
    char choice;
    int value;
  cout << "\n :: Binary search tree ::\n 1.INSERT A NODE \n 2.PREORDER TRAVERSAL \n3.EXIT";
;
    while (choice != 3)
    {
      
        cout << "ENter your choice";

        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Node inserted successfully!" << endl;
            break;

        case '2':
        cout<<"\npreorder traversal ::";
            preorder(root);
            cout<<endl;
            break;
            case '3':
            return 0;
       
}
}
return 0;
}