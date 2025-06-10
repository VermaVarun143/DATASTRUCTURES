#include <iostream>
//STL STACK 
#include <stack>
using namespace std;
int main()
{
    // creation of stack
    stack<int> s;

    // push
    s.push(2);
    s.push(3);
    s.push(5);

    // pop
    s.pop();

    // top
    cout << "\nPrint top ELement" << s.top();

    //empty
    if(s.empty()){
        cout<<"\nstack is empty";
    
    }
    else{
        cout<<"\nStack is not empty";
    }


    //size
    cout<<"\nSize of STack is"<<s.size();
}
