#include <stdio.h>
#include <stdlib.h>
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
void insertspecific(int data,int location);
void main()
{int a,b;
    int choice = 0;
    printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");
    while (choice != 7)
    {
        
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            begin_delete();
            break;
        case 4:
            last_delete();
            break;
        case 5:
            search();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        case 8:
        printf("Enter Value and Location after which you want to insert");
        scanf("%d %d",&a,&b);
            insertspecific(a,b);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void beginsert()
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
        printf("\nEnter the node data?");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nnode inserted\n");
    }
}
void lastinsert()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data?");
        scanf("%d", &item);
        newnode->data = item;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }

        printf("\nnode inserted\n");
    }
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }

    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode deleted\n");
    }
}
void insertspecific(int data, int location)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Overflow");
    }
    else
    {
        newnode->data=data;
        if (head == NULL && location == 0)
        {
            newnode->next = newnode;
            head = newnode;
        }
        else if (location == 0)
        {
            struct node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
        else
        {
            struct node *temp = head;
            for (int i = 0; i < location; i++)
            {
                temp = temp->next;
                if (temp == head)
                {
                    printf("Cant insert");
                    return;
                }
            }
            
           
                newnode->next=temp->next;
                temp->next=newnode;
            
        }
    }
}
void last_delete()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void search()
{
    struct node *ptr;
    int item, i = 1, flag = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
       
        
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("item found at location %d ", i );
                    flag = 1;
                    return;
                }
                
                i++;
                ptr = ptr->next;
            }
        }
        if (flag == 0)
        {
            printf("Item not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values ... \n");

        while (ptr->next != head)
        {

            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}