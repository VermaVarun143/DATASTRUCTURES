#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void deletemid();
void insertmid();
int main()
{
    int choice = 0;
    cout << "\n\n*********Main Menu*********\n";
    cout << "\nChoose one option from the following list ...\n";
    cout << "\n===============================================\n";
    cout << "\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last\n6.Delete node after specified location \n7.Search for an element \n8. Show\n9.Exit\n10.deletemid\n11.insertmid";

    while (choice != 9)
    {

        cout << "\nEnter your choice?";
        cin >> choice;
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        case 10:
            deletemid();
            break;
        case 11:
            insertmid();
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}

void beginsert()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(newnode));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = head;
        head = newnode;
        printf("\nNode inserted");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}

void randominsert()
{
    int i, loc, item;
    struct node *temp, *newnode;

    // Dynamically allocate memory for the new node
    newnode = (struct node*)malloc(sizeof(struct node));  // Corrected memory allocation
    if (newnode == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }
    
    // Get the data for the new node
    printf("\nEnter element value: ");
    scanf("%d", &item);
    newnode->data = item;
    newnode->next = NULL;  // The new node's next pointer should initially be NULL

    // Get the location after which to insert the new node
    printf("\nEnter the location after which you want to insert: ");
    scanf("%d", &loc);

    // Special case: if the list is empty and loc is 0
    if (head == NULL && loc == 0)
    {
        head = newnode;
        printf("\nNode inserted at the beginning as the list was empty.\n");
        return;
    }

    // Traverse the list to find the node after which to insert
    temp = head;
    for (i = 1; i < loc; i++)
    {
        if (temp == NULL)
        {
            printf("\nCan't insert. Invalid location.\n");
            return;
        }
        temp = temp->next;
    }

    // Insert the new node after the found location
    newnode->next = temp->next;
    temp->next = newnode;
    
    printf("\nNode inserted after location %d\n", loc);
}


void insertmid()
{
    int size = 0, mid = 0, val;
    struct node *temp, *temp1;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));
    printf("ENter The Value To insert");
    scanf("%d", &val);

    newnode->data = val;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    if (size % 2 == 0)
    {
        mid = size / 2;
    }
    else
    {
        mid = (size + 1) / 2;
    }
    temp = head;

for(int i=0;i<mid-1;i++){
    temp=temp->next;
}

newnode->next=temp->next;
temp->next=newnode;
printf("Node Inserted");

}
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}

void last_delete()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}
void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc - 1; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    int ans = ptr->data;
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node data:  %d ", ans);
}

void deletemid()
{
    int size = 0, mid = 0;
    struct node *temp, *temp1;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    if (size % 2 == 0)
    {
        mid = size / 2;
    }
    else
    {
        mid = (size + 1) / 2;
    }
    temp = head;
    for (int i = 0; i < mid - 1; i++)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    free(temp);
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
