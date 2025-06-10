#include <iostream>
using namespace std;

// Define a node structure for linked list representation of a sparse matrix
struct Node {
    int row, col, value;
    Node* next;

    Node(int r, int c, int val) : row(r), col(c), value(val), next(nullptr) {}
};

// Function to create linked list representation of sparse matrix
Node* linkedListRepresentation(int matrix[][4], int rows, int cols) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                Node* newNode = new Node(i, j, matrix[i][j]);
                if (!head) {
                    head = tail = newNode; // Initialize head and tail
                } else {
                    tail->next = newNode; // Link new node to the list
                    tail = newNode; // Update tail
                }
            }
        }
    }
    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    cout << "Linked List Representation (Row, Col, Value):" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << "(" << current->row << ", " << current->col << ", " << current->value << ") -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to delete the linked list and free memory
void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp; // Free memory for each node
    }
}

int main() {
    // Sample sparse matrix
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 0, 0, 5},
        {0, 17, 0, 0}
    };

    // Linked List Representation
    Node* linkedList = linkedListRepresentation(matrix, 4, 4);
    printLinkedList(linkedList);
    
    // Clean up memory
    deleteLinkedList(linkedList);

    return 0;
}