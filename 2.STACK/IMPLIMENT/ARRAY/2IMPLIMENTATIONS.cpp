#include <iostream>
#include <string>
#include <stack>
int arr[5], top = -1, i, size = 5;
using namespace std;
void push()
{
    int num;
    if (size - top > 1)
    {

        cout << "Enter New Element";

        cin >> num;
        top++;
        arr[top] = num;
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

        int ans = arr[top];
        top--;
        cout << "Element " << ans << " Pushed\n";
    }
    else
    {
        cout << "Stack is Empty";
        return -1;
    }
}
int top1()
{
    if (top > -1)
    {
        cout << "Top ELement:: " << arr[top] << endl;
    }
}

int show1()
{
    if (top > -1)
    {
        cout << "STack ELement";
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i];
        }
    }
}
void reverse(string s)
{
    stack<char> st;
    char ch;
    int size=0;
    for (int i = 0; i < s.length(); i++)
    {
        
        ch = s[i];
        st.push(ch);
        size++;

    }
    cout<<"\n\nSIze of string is "<<size;
  string ans="";
   
    while(!st.empty()){
       
       
       ans=ans+st.top();
       st.pop();
       
    }
    cout<<"\nREversed string is:: "<<ans;
    
}
int main()
{

    char choice;
    do
    {
        cout << "\n 1.PUSH :";
        cout << "\n 2.POP :";
        cout << "\n 3.TOP :";
        cout << "\n 4.SHOW :";
        cout << "\n 5.EXIT :";
        cout << "\n 6.Reverse :";
        
        cout << "\nChoice:: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            push();
            break;
        case '2':
            pop();
            break;
        case '3':
            top1();
            break;
        case '4':
            show1();
            break;
        case '5':
            return 0;
            break;
        case '6':
            string s;
            cout << "ENter A String";
            cin >> s;
            reverse(s);
        }
    } while (choice != 4);
    return 0;
}