#include <iostream> // For standard input/output
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

// Function to create a binary tree node
Node *create()
{
    struct Node *temp;
    char data;
    int choice;

    cout << "\nPress 0 to exit, 1 for a new node";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 0)
    {
        return nullptr; // Exit if the choice is 0
    }

    // Allocate memory for a new node
    temp = new Node;

    cout << "Enter the data: ";
    cin >> data;
    temp->data = data;

    // Recursively create left and right children
    cout << "Enter the left child of " << data << ":\n";
    temp->left = create();

    cout << "Enter the right child of " << data << ":\n";
    temp->right = create();

    return temp; // Return the created node
}
void preorder(Node *temp) // root left right
{
    if (temp == nullptr)
    {
        return;
    }

    cout << temp->data << " ";

    preorder(temp->left);
    preorder(temp->right);
}
void inorder(Node *l)
{ // left root right
    if (l == nullptr)
    {
        return;
    }

    inorder(l->left);
    cout << l->data << " ";
    inorder(l->right);
}
void postorder(Node *r) // left right root
{
    if (r == nullptr)
    {
        return;
    }

    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}
int countnodes(Node *temp)
{
    if (temp == nullptr)
    {
        return 0;
    }
    int leftCount = countnodes(temp->left);
    int RightCount = countnodes(temp->right);
    return 1 + leftCount + RightCount;
}
int main()
{
    Node *root; // Root node pointer
    cout << "Creating the root node of the binary tree:\n";
    root = create(); // Start the creation with the root node
    preorder(root);
    cout << endl;
    inorder(root);
    // 1A1B1D0001C1E01G001F1H001I00
    cout << endl;
    postorder(root);
   int nodenumber= countnodes(root);
   cout<<"\nNUMBER OF NODES IS"<<nodenumber;
    return 0;
}
