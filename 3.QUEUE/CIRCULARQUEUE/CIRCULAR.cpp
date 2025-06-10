#include <iostream>
using namespace std;

#define max 5  // Maximum size of the queue

// Circular Queue class
class CircularQueue {
private:
    int queue[max];  // Array to store queue elements
    int front, rear;  // Front and rear pointers

public:
    // Constructor to initialize queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation (Insert element in the queue)
    void enqueue(int element) {
        if ((rear + 1) % max == front) {  // Check if the queue is full
            cout << "\nQueue is overflow.. Cannot insert element!" << endl;
        } else {
            if (front == -1) {  // If the queue is empty
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % max;  // Circular increment of rear
            }
            queue[rear] = element;  // Insert element at the rear
            cout << "\nElement " << element << " inserted successfully!" << endl;
        }
    }

    // Dequeue operation (Remove element from the queue)
    void dequeue() {
        if (front == -1) {  // Check if the queue is empty
            cout << "\nQueue is underflow.. Cannot remove element!" << endl;
        } else {
            cout << "\nElement " << queue[front] << " removed!" << endl;
            if (front == rear) {  // If the queue becomes empty after dequeue
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % max;  // Circular increment of front
            }
        }
    }

    // Display elements of the queue
    void display() {
        if (front == -1) {  // Check if the queue is empty
            cout << "\nQueue is empty.." << endl;
        } else {
            cout << "\nElements in the Queue are: ";
            int i = front;
            while (true) {
                cout << queue[i] << " ";  // Print current element
                if (i == rear)  // Stop when we reach the rear
                    break;
                i = (i + 1) % max;  // Circular increment of index
            }
            cout << endl;
        }
    }
};

// Main function with menu-driven interface
int main() {
    CircularQueue cq;  // Create a CircularQueue object
    int choice, element;

    while (true) {
        // Display the menu
        cout << "\nCircular Queue Operations Menu: ";
        cout << "\n1. Enqueue (Insert element)";
        cout << "\n2. Dequeue (Remove element)";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;
 switch (choice) {
            case 1:
                cout << "\nEnter the element to enqueue: ";
                cin >> element;
                cq.enqueue(element);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.display();
                break;

            case 4:
                cout << "\nExiting the program...\n";
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}

