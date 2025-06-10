#include <stdio.h>
#include<string.h>

int arr[10], size = 10, top = -1;
void push(int num)
{
    if (size - top > 1)
    {
        top++;
        arr[top] = num;
        printf("Element isadded in stack\n");
    }
    else
    {
        printf("Stack is Overflow");
    }
}
void pop()
{
    if (top == -1)
    {
        printf("STack is empty\n");
    }
    else
    {
        int a = top;
        top--;
        printf(" %d Element is Popped", arr[a]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("STack is empty");
    }
    else
    {
        printf("\n    STack Elements:: ");
        int j;
        for (j = top; j >= 0; j--)
        {
            printf(" %d ", arr[j]);
        }
    }
}

void peek()
{
    if (top == -1)
    {
        printf("STack IS empty");
    }
    else
    {
        int a = top;
        printf("Top ELement is :: %d", arr[a]);
    }
} 



int main()
{
    int choice;

    while (choice != 5)
    {
        printf("\n1.PUSH\n2.POP\n3.Display\n4.TOP ELEMENT\n5.EXIT\nENter YOur choice");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int n;
            printf("ENter the number");
            scanf("%d", &n);
            push(n);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            peek();
        }
        else
        {
            printf("invalid choice");
        }
    }
    return 0;
}