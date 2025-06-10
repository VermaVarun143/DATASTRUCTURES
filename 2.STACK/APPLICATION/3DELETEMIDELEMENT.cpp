#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, count + 1, size);
    s.push(num);
}

void deletemiddle(stack<int>&st, int N)
{
    int count = 0;
    solve(st, count, N);
}

int main()
{
    stack<int> st;
    cout << "1.PUSH\n 2.POP \n3.DELETE MID\n4.EXIT\n5.DISPLAY ";
    char choice;

    do
    {
        cout << "\nEnter Your Choice::";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "\nENTER ELEMENT";
            int n;
            cin >> n;
            st.push(n);
            break;
        case '2':
            st.pop();
            break;
        case '3':
            deletemiddle(st, st.size());
            break;
        case '4':
            exit(1);
            break;
        case '5':
            cout << "\n\nSTACK::  ";
            stack<int> stack;
                stack = st;
            while (!stack.empty())
            {
                
                int ans = stack.top();
                stack.pop();
                cout << ans << " ";
                
            }
            break;
        }
    } while (choice != 4);
}