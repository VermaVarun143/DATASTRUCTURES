#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
void insert_bottom1(stack<int> &st,int n)
{
   if(st.empty()){
    st.push(n);
    return ;
   }
   int ans=st.top();
   st.pop();
   insert_bottom1(st,n);
st.push(ans);

}
int main()
{

    cout << "1.PUSH\n 2.POP \n3.BOTTOM INSERT\n4.EXIT\n5.DISPLAY ";
    char choice;
stack<int> st;
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
            cout << "\nEnter the Element to INsert at BOttom";

            int num;
            cin >> num;
            insert_bottom1(st,num);
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
