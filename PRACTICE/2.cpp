#include<iostream>
using namespace std;
int funt(int x,int y);

int main(){
    int x,y;
    x=50;y=40;
  funt(x,y);
    cout<<x<<endl<<y;

    }


int funt(int x,int y){
   x=x*x;
  y=y* y;
    return x;
    }