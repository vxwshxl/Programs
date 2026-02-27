//13. Write a constructor in c++ to swap the values of two input numbers with a third variable and without using 3rd variable using the concept of constructor overloading

#include<iostream>
#include<stdlib.h>
using namespace std;

class swap1 {
  int x1,y1;
  public:
    swap1();
    swap1(int,int);
};

swap1::swap1() {
  int a1,b1,t1;
  cout<<endl<<"Enter the values of A:";
  cin>>a1;
  cout<<endl<<"Enter the values of B:";
  cin>>b1;
  cout<<endl<<"Before SwapA="<<a1<<"and B="<<b1;
  t1=a1;
  a1=b1;
  b1=t1;
  cout<<endl<<"After SwapA="<<a1<<"and B="<<b1;
}

swap1::swap1(int x,int y) {
  cout<<endl<<"Enter the values of A:";
  cin>>x;
  cout<<endl<<"Enter the values of B:";
  cin>>y;
  cout<<endl<<"Before SwapA="<<x<<"and B="<<y;
  x=x+y;
  y=x-y;
  x=x-y;
  cout<<endl<<"After SwapA="<<x<<"and B="<<y;
}

int main() {
  int a1,b1;
  cout<<endl<<"Constructor Overloading:";
  cout<<endl<<"SWAP(with 3rd variable:)";
  swap1 sw;
  cout<<endl<<"SWAP(Without using 3rd variable)";
  swap1 se(a1,b1);
}


// Output:
Constructor Overloading:
SWAP(with 3rd variable:)
Enter the values of A:5

Enter the values of B:6

Before SwapA=5and B=6
After SwapA=6and B=5
SWAP(Without using 3rd variable)
Enter the values of A:8

Enter the values of B:9

Before SwapA=8and B=9
After SwapA=9and B=8