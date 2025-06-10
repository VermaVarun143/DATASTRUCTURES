#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node* next;
}*head=nullptr;

// Function to insert a new node at the beginning
void push( int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to reverse the linked list
void reverse() {
    Node* prev = nullptr;   // Initially, no previous node
    Node* current = head;   // Start with the head node
    Node* next = nullptr;   // Next node to be processed

    // Traverse the list and reverse the links
    while (current != nullptr) {
        next = current->next;      // Save the next node
        current->next = prev;      // Reverse the link
        prev = current;            // Move prev to current node
        current = next;            // Move current to next node
    }

    head = prev;  // Update head to point to the new first node
   

}

// Function to display the linked list
void printList() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
     // Start with an empty list
    int choice, data;

    do {
        cout << "\nMenu: \n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Display List\n";
        cout << "3. Reverse List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                push(data);
                cout << data << " inserted at the beginning." << endl;
                break;

            case 2:
                cout << "The linked list is: ";
                printList();
                break;

            case 3:
             cout << "The linked list in reversed. FORM ::" ;
                reverse();
                printList();
                reverse();
               
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
