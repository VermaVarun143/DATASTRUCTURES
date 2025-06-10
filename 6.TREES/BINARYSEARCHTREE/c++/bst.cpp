#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insertion in Binary Search Tree
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);  // Create a new node if root is nullptr
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree if data is smaller
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree if data is larger
    }

    return root;
}

// Search for a node in Binary Search Tree
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;  // Return the node if found, or nullptr if not found
    }

    if (key < root->data) {
        return search(root->left, key);  // Search in left subtree if key is smaller
    } else {
        return search(root->right, key);  // Search in right subtree if key is larger
    }
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;  // Keep going left to find the minimum
    }
    return root;
}

// Deletion in Binary Search Tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;  // Return nullptr if the tree is empty
    }

    // Search for the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // If key is smaller, go left
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // If key is larger, go right
    } else {
        // Node to be deleted is found

        // Node has one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;  // Free the memory
            return temp;   // Return the right child or nullptr
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;  // Free the memory
            return temp;   // Return the left child
        }

        // Node has two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit the node
        preorder(root->left);       // Traverse left subtree
        preorder(root->right);      // Traverse right subtree
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);       // Traverse left subtree
        cout << root->data << " ";  // Visit the node
        inorder(root->right);      // Traverse right subtree
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        cout << root->data << " ";  // Visit the node
    }
}

// Function to display the menu options
void displayMenu() {
    cout << "\n---- Binary Search Tree User Manual ----" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Search for a node" << endl;
    cout << "3. Delete a node" << endl;
    cout << "4. Perform Inorder Traversal" << endl;
    cout << "5. Perform Preorder Traversal" << endl;
    cout << "6. Perform Postorder Traversal" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    Node* root = nullptr;  // Initialize root to nullptr
    int choice, value;

    while (true) {
        displayMenu();  // Display the menu
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Insert a node
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Node inserted successfully!" << endl;
                break;

            case 2:  // Search for a node
                cout << "Enter value to search for: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Node with value " << value << " found!" << endl;
                } else {
                    cout << "Node with value " << value << " not found." << endl;
                }
                break;

            case 3:  // Delete a node
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Node deleted successfully!" << endl;
                break;

            case 4:  // Inorder traversal
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:  // Preorder traversal
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 6:  // Postorder traversal
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:  // Exit
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
