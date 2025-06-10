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
// Postorder traversal: Left -> Right -> Root
void postorder(node *root)
{
    if (root == nullptr)
    {
        
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = nullptr;
    char choice;
    int value;
  cout << "\n :: Binary search tree ::\n 1.INSERT A NODE \n 2.POSTORDER TRAVERSAL \n3.EXIT";
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
        cout<<"\npostorder traversal ::";
            postorder(root);
            cout<<endl;
            break;
            case '3':
            return 0;
       
}
}
return 0;
}