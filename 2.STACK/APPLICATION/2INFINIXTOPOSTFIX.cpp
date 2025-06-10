#include <iostream>
#include <stdlib.h>
#include <cstring>
#define MAX 100
using namespace std;

char stack[MAX];
char infinix[MAX], postfix[MAX];
int top = -1;
void push1(char s)
{
    if (MAX - top > 1)
    {
        top++;
        stack[top] = s;
    }
    else
    {
        cout << "Stack is Overflow";
    }
}
int pop()
{
    if (top > -1)
    {
        char ans = stack[top];
        top--;
        return ans;
    }
    else
    {
        cout << "stack is empty";
    }
}
int precendence(char s)
{
    if (s == '+')
    {
        return 1;
    }

    else if (s == '-')
    {
        return 1;
    }
    else if (s == '*')
    {
        return 2;
    }
    else if (s == '/')
    {
        return 2;
    }
    else if (s == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int isEMPTY()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// int space(char c)
// {
//     if (c == '  ' || c == '\t')
//         return 1;

//     else
//         return 0;
// }
void Post_Funt(char *str)
{
    int j = 0;
    char symbol, next;
    for (int i = 0; i < strlen(str); i++)
    {
        symbol = infinix[i];
        if (symbol != ' ' || symbol!='\t')
        {
            switch (symbol)
            {
            case '(':
                push1(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEMPTY() && precendence(stack[top]) >= precendence(symbol))
                    postfix[j++] = pop();
                push1(symbol);

                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while (!isEMPTY())
    {
        postfix[j++] = pop();
        postfix[j] = '\0';
    }
}
int print()
{
    cout << "\n\nEQIVALENT POSTFIX EXPRESSION IS :: ";
    for (int i = 0; i < strlen(postfix); i++)
    {
        cout << postfix[i];
    }
}
int main()
{
    cout << "Enter The Infinix Expression:: ";
    cin >> infinix;
    Post_Funt(infinix);

    print();
    return 0;
}