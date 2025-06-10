#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct node {
    int data;
    struct node *left, *right;
};
// Function to create a new node or to stop creation based on user input
struct node* create() {
    struct node *temp;     // Temporary pointer for a new node
    int data, choice;      // Data to be stored and choice to continue or stop

    // Allocate memory for a new node
    temp = (struct node*)malloc(sizeof(struct node));

    // Check if memory allocation failed
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // User input for node creation
    printf("\nPress 0 to exit, 1 for a new node\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // If user chooses 0, exit and return NULL
    if (choice == 0) {
        free(temp); // Free memory since we won't use this node
        return NULL;
    } else {
        // User chooses to create a new node
        printf("Enter the data: ");
        scanf("%d", &data);
        temp->data = data;

        // Recursively create left child
        printf("Enter the left child of %d:\n", data);
        temp->left = create();

        // Recursively create right child
        printf("Enter the right child of %d:\n", data);
        temp->right = create();

        return temp; // Return the newly created node
    }
}


int main() {
    struct node *root; // Create a pointer for the root of the tree
    printf("Creating the root node of the binary tree:\n");
    root = create();   // Initialize the tree starting with the root
    return 0;
}

