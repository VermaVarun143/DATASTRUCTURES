#include <iostream>
using namespace std;

// Define a structure to represent a node in the priority queue
struct Node {
    int data;      // Data of the element
    int priority;  // Priority of the element
    Node* next;    // Pointer to the next node in the queue
};

// Define a structure to represent the priority queue
Node* front=nullptr;
    // Function to insert an element into the priority queue
    void insert(int data, int priority) {
        Node* newNode = new Node;  // Create a new node
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = nullptr;

        // If the queue is empty or the new node has higher priority than the front node
        if (front == nullptr || front->priority < priority) {
            newNode->next = front;
            front = newNode;  // Insert at the front
        }
        else {
            // Find the correct position for the new node
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Element inserted: " << data << " with priority " << priority << endl;
    }

    // Function to delete the element with the highest priority
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;  // Save the front node to delete it
        front = front->next;  // Move the front pointer to the next node
        delete temp;          // Delete the old front node
        cout << "Highest priority element removed." << endl;
    }

    // Function to display the elements in the priority queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Priority Queue elements:" << endl;
        while (temp != nullptr) {
            cout << "Data: " << temp->data << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }


// Main function for menu-driven interface
int main() {
    
    int choice, data, priority;

    do {
        cout << "\nPriority Queue Menu" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Dequeue element" << endl;
        cout << "3. Display elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insert element with a priority
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority: ";
                cin >> priority;
                insert(data, priority);
                break;
            
            case 2:
                // Dequeue the element with the highest priority
                dequeue();
                break;

            case 3:
                // Display all elements in the priority queue
                display();
                break;

            case 4:
                // Exit the program
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 4);  // Loop until the user chooses to exit

    return 0;
}
