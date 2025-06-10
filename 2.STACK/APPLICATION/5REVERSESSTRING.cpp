#include <iostream>
#include <stack>
using namespace std;

void temp(string s)
{
    cout << "reverse" << s;
}
int main()
{
    int i;
    string str;
    cin >> str;
    stack<char> st;
int size=0;
    for (i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
        size++;
    }
    cout<<"Size of string is "<<size;
    string ans;
    while (!st.empty())
    {
        char ch = st.top();
        ans.push_back(ch);

        st.pop();
    }
    cout << "Reverse:::    " << ans;

    return 0;
}