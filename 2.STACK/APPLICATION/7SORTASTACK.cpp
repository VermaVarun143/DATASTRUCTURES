#include <iostream>
#include <stack>
using namespace std;

void sortinsert(stack<int> &sort, int num)
{
    // base case
    if (sort.empty() || (!sort.empty()) && sort.top() < num)
    {
        sort.push(num);
        return;
    }
    int n = sort.top();
    sort.pop();

    sortinsert(sort, num);
    sort.push(n);
}

void solve(stack<int> &sort)
{
    if (sort.empty())
    {
        return;
    }
    int num = sort.top();
    sort.pop();

    // recursivecall
    solve(sort);

    sortinsert(sort, num);
}
int main()
{
    cout << "1.PUSH\n 2.POP \n3.SORT A STACK:\n4.EXIT\n5.DISPLAY ";
    char choice;
    stack<int> st,varun;
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
             solve(st);
             varun=st;
             cout<<"\n SORTED STACK::";
             while(!varun.empty()){
                int ans=varun.top();
                varun.pop();
                cout<<ans<<" ";

             }
            

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
