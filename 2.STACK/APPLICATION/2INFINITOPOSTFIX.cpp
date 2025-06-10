#include <iostream>
 #include <string>
 #include <stack>


using namespace std;

stack<char> st;
string result;
int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol =='+' || symbol == '-')
        return 1;
    else
        return 0;
}

int infinixtopost(string s)
{
   
  
    char symbol;
    for (int i = 0; i < s.length(); i++)
    {
        symbol = s[i];

        if (symbol == '(')
        {
            st.push(symbol);
        }
        else if (symbol == ')')
        {
            while (st.top() != '(')
            {
                result = result + st.top();
                st.pop();
            }
            st.pop();
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            while (!st.empty() && precedence(st.top()) >= precedence(symbol))
            {

                result = result + st.top();
                st.pop();
            }
            st.push(symbol);
        }
        else
        {
            result = result + symbol;
        }
    }
    while (!st.empty())
    {
        result = result +  st.top();
        st.pop();
        
        
    }
   
}
// int print()
// {
//     cout << "\n\nEQIVALENT POSTFIX EXPRESSION IS :: ";
//     for (int i = 0; i <result.length(); i++)
//     {
//         cout << result[i];
//     }
// }
int main()
{
    
    
string exp;
cout<<"\n enter the infinix expression";
getline(cin,exp);

infinixtopost(exp);
cout<<"\nEquivalent postfix expression is"<<result;
    return 0;
}
