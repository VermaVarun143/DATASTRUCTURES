#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void forwarddisplay();
void backwarddisplay();
void search();
void main()
{
    int a, b;
    printf("\n*********Main Menu*********\n");
    printf("\n===============================================\n");
    printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.forwardtraverse\n9.backwarddisplay\n10.Exit\n");
    int choice = 0;
    while (choice != 9)
    {

        printf("\nChoose one option from the following list ...\n");

        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:

            printf("Enter value");
            scanf("%d", &a);
            printf("Enter location");
            scanf("%d", &b);
            insertion_specified(a, b);
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            forwarddisplay();
            break;
        case 9:
         backwarddisplay();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item value");
        scanf("%d", &item);
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = item;
        if (head == NULL)
        {

            head = newnode;
        }
        else
        {

            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        printf("\nNode inserted\n");
    }
}
void insertion_last()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value");
        scanf("%d", &item);
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = item;
        if (head == NULL)
        {

            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    printf("\nnode inserted\n");
}
void insertion_specified(int it, int loca)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = head;

        for (int i = 0; i < loca; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loca);
                return;
            }
        }

        newnode->data = it;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
        printf("\nnode inserted\n");
    }
}
void deletion_beginning()
{
    struct node *TEMP;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        TEMP = head;
        head = head->next;
        head->prev = NULL;
        free(TEMP);
        printf("\nnode deleted\n");
    }
}
void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void deletion_specified()
{
    struct node *temp, *temp1;
    int val;
    printf("\n Enter the location after which the node is to be deleted : ");
    scanf("%d", &val);
    temp = head;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        for (int i = 0; i < val; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("invalid location");
                return;
            }
        }
        if (temp->next == NULL)
        {
            printf("\nCan't delete\n");
        }
        else if(temp->next->next==NULL){
            temp->next =NULL;
        }
        else
        {
            temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
            printf("\nnode deleted\n");
        }
    }
}
void forwarddisplay()
{
    struct node *temp;
    printf("\n printing values...\n");
    temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
void backwarddisplay(){
    if(head==NULL){
        printf("No nodes");
    }
    else{
        struct node*temp=head ;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->prev;

        }
    }
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag=0;
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
                printf("\nitem found at location %d ", i + 1);
                flag = 1;
               return;
            }
           
            i++;
            ptr = ptr->next;
        }
        if (flag == 0)
        {
            printf("\nItem not found\n");
        }
    }
}
