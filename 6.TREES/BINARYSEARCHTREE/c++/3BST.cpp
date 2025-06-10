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
  cout << "\n :: Binary search tree ::\n 1.INSERT A NODE \n 2.INORDER TRAVERSAL \n 3. PREORDER TRAVERSAL \n 4. POSTORDER TRAVERSAL \n 5.EXIT \n";
    while (choice != 5)
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
        cout<<"\nINorder traversal :: ";
            inorder(root);
            cout<<endl;
            break;
        case '3':
        cout<<"\nPreorder traversal ::";
            preorder(root);
            cout<<endl;
            break;
        case '4':
        cout<<"\n Post-order traversal::";
            postorder(root);
            cout<<endl;
            break;
            case '5':
            cout<<"\nEXIT THE PROGRAM\n";
            return 0;
        }
    }
    return 0;
}
