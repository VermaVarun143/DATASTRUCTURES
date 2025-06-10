#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Insert function that creates and inserts nodes as needed
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node;           // Allocate memory for a new node directly
        root->data = data;         // Assign data
        root->left = root->right = nullptr; // Initialize children to nullptr
    } else if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insert in the right subtree
    }
    return root;
}

// Search function for Binary Search Tree
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;  // Return the node if found, or nullptr if not found
    }
    if (key < root->data) {
        return search(root->left, key);  // Search in left subtree
    } else {
        return search(root->right, key); // Search in right subtree
    }
}

// Function to find the largest node in the left subtree
Node* findmin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    // Step 1: Locate the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        // Step 2: Find the smallest node in the right subtree
        Node* minright= findmin(root->right);

        // Step 3: Copy the smallest value from the right subtree to this node
        root->data = minright->data;

        // Step 4: Delete the duplicate node in the right subtree
        root->left = deleteNode(root->left, minright->data);
    }
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Display menu for user
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
