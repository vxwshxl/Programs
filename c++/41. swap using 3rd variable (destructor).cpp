// 41. Write a constructor in c++ to input the two numbers and print the swaped values using 3rd variable using destructor

#include <iostream>
using namespace std;

class swap1 {
    int a,b,t;
    public:
        swap1();//constructor
        ~swap1();//destructor
};

swap1::swap1() {
    cout<<endl<<"Enter the values of A:";
    cin>>a;
    cout<<endl<<"Enter the values of B:";
    cin>>b;
    cout<<endl<<"Before swap A="<<a<<"and B="<<b;
    t=a;
    a=b;
    b=t;
}

swap1::~swap1() {
    cout<<endl<<"using Destructor:";
    cout<<endl<<"After swap A="<<a<<"and B="<<b;
}
int main() {
    swap1 t1;
}


// Output:
Enter the values of A:5

Enter the values of B:6

Before swap A=5and B=6
using Destructor:
After swap A=6and B=5