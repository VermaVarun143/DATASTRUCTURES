#include <iostream>
#include <stack>
using namespace std;
int insertBOTTOM(stack<int> &st, int n)
{
    if (st.empty())
    {
        st.push(n);
    }
    int ans = st.top();
    st.pop();
    insertBOTTOM(st, n);
    st.push(ans);
}
void REVERSE(stack<int> &stack)
{
    if (stack.empty())
    {
        return ;
    }
    int num = stack.top();
    stack.pop();

    REVERSE(stack);
    insertBOTTOM(stack, num);
}

int main()
{

    cout << "1.PUSH\n 2.POP \n3.BOTTOM INSERT\n4.EXIT\n5.DISPLAY ";
    char choice;
    stack<int> st, varun;
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
            cout << "\nREVERSE";

            REVERSE(st);
            varun = st;
            cout << "\n SORTED STACK::";
            while (!varun.empty())
            {
                int ans = varun.top();
                varun.pop();
                cout << ans << " ";
            }

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
