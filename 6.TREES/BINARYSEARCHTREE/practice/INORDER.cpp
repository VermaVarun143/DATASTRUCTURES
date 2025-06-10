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
// Inorder traversal: Left -> Root -> Right
void inorder(node *root)
{
    if (root == nullptr)
    {
       
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = nullptr;
    char choice;
    int value;
  cout << "\n :: Binary search tree ::\n 1.INSERT A NODE \n 2.INORDER TRAVERSAL \n3.EXIT";
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
        cout<<"\nINorder traversal ::";
            inorder(root);
            cout<<endl;
            break;
            case '3':
            return 0;
       
}
}
return 0;
}
