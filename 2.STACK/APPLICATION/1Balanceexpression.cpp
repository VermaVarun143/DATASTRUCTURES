#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkexpressions(string exp)
{
    stack<char> st;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
            {
                cout << "Not valid expression";
                return 0;
            }
            else
            {
                char top = st.top();
                if (ch == ')' && top == '(' ||
                 ch == '}' && top=='{' ||
                  ch == ']' && top=='['){
                    st.pop();
                  }
                 else {
                    cout << "\nMismatched brackets. Not a valid expression.";
                    return 0;
                }
            }
        }
    }

    if(st.empty()){
        cout<<"\nExpression is valid";
    }
    else{
        cout<<"\n Expression Not valid";
    }
}

int main(){

    string expression;
    cout<<"Enter the Expression  ::  ";
    cin>>expression;

    checkexpressions(expression);
    return 0;

}
