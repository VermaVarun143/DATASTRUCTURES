#include <iostream>
using namespace std;
class stack
{
    // properties
    int top;
    int *arr;
    int size;
public:
    // behaviour
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack Overflow";
        }
    }
    void pop()
    {
        if (top >-1)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow";
        }
    }
    int peek()
    {
        if (top >= 0 )
        {
            return arr[top];
        }
        else{
            cout<<"Stack IS Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    stack st(5);
    st.push(5);
    st.push(8);
    st.push(56);
    st.push(76);


    st.pop();
    st.pop();
    st.pop();
    st.pop();

   cout<< st.peek();
if(st.isEmpty()){
    cout<<"Array is empty";
}




}