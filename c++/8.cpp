// 8. Write a constructor and copy constructor in c++ to swap the values of two input terms without using 3rd variable.

#include<iostream>
using namespace std;

class swap1{
    int a;
    int b;
    public:
    swap1(int,int);
    swap1(swap1 &);
    void display();
};

swap1::swap1(swap1 &t) {
    a=t.a;
    b=t.b;
}

swap1::swap1(int x,int y) {
    cout<<endl<<"Enter the Value of X:";
    cin>>x;
        cout<<endl<<"Enter the Value of Y:";
        cin>>y;
        a=x;
        b=y;
       cout<<endl<<"Values Before Swap: X="<<a<<"and Y="<<b;
       a=a+b;
       b=a-b;
       a=a-b;
}

void swap1::display() {
    cout<<endl<<"Values After Swap: X="<<a<<"and Y="<<b;
}

int main() {
    int a1,b1;
    swap1 s(a1,b1);
    s.display();
    cout<<endl<<"Copy constructor called";
    swap1 copycon(s);
    copycon.display();
}

// Output:
Enter the Value of X:5

Enter the Value of Y:67

Values Before Swap: X=5and Y=67
Values After Swap: X=67and Y=5
Copy constructor called
Values After Swap: X=67and Y=5