#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int top = -1;
char stack[100];

void push(char a)
{
    if (100 - top > 1)
    {
        top++;
        stack[top] = a;
    }
    else
    {
        cout << "Stack IS Overflow";
    }
}

int pop1()
{
    if (top > -1)
    {
        int ans = stack[top];
        top--;
        return ans;
    }
    else
    {
        cout << "Stack Is UNderflow";
        return 0;
    }
}

int isEmpty()
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


int match_char(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    if (a == '{' && b == '}')
        return 1;

    return 0;
}

int check_balanced(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    { // if string have left brackets then push to stack
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            push(s[i]);
        }
        // if string have right brackets than do following
        else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if (isEmpty())
            {//if stack is empty then unvalid
                cout << "\nRIGHT BRAKCETS ARE MORE THAN LEFT BRACKET\n";
                return 0;
            }
            else
            {//if stack is not empty then pop the top element of stack
                char temp = pop1();
                if (!match_char(temp, s[i]))
                {
                    cout << "\nMISMATCH BRACKERTS\n";
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        cout << "\nBracket is well balanaced\n";
        return 1;
    }
    else
    {
        cout << "\n Brackets are not balanced";
        return 0;
    }
}

int main()
{
    char ex[100];
    int BALANCED;
    cout << "Enter The Expression";
    gets(ex);

    BALANCED = check_balanced(ex);
    if (BALANCED == 1)
    {
        cout << "THE EXPRESSION IS VALID";
    }
    else
    {
        cout << "Expression is not valid";
    }
    return 0;
}
