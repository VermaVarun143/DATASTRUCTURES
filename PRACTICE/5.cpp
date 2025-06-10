#include<iostream>
using namespace std;
int main(){
    static int var;
    for(int i=0;i<5;i++){
        ++var;
        cout<<var<<endl;
    }
  cout<<var<<endl;
    return 0;
}