#include<iostream>
using namespace std;
class stack{
    int *arr;
    int top1,top2;
    int size;
    public:
stack(int s){ 
size=s;
top1=-1;
top2=s;
arr =new int [size];
}

void push1(int num){
    if(top2-top1 >1){
      top1++;
      arr[top1]=  num;
    }
    else{
        cout<<"Stack Overlow";
    }
}
    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
            cout<<"stack Overflow";
        }
    }

int pop1(){
if(top1>-1){
int ans=arr[top1];
    top1--;
    return ans;
}
else{
    return -1;
}
}
int pop2(){
if(top1<size){
    int ans=arr[top2];
    top1++;
    return -1;
}
else{
    return -1;
}
}
int peek1(){
    if(top1>-1){
        return arr[top1];
    }
}
    
};
int main(){
    stack st(10);
    st.push1(5);
    st.push1(6);
    st.push1(7);
    st.push1(8);
    st.push1(9);
    st.push1(20);
    st.push2(20);
    st.push2(23);
    st.push2(25);
cout<<st.peek1();
st.pop1();
st.pop1();
st.pop1();
cout<<st.peek1();

}