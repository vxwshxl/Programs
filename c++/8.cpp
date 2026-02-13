//8. Write a constructor and copy constructor in c++ to swap the values of two input terms without using 3rd variable.

#include<iostream>
using namespace std;

class swap1
{   int a;
    int b;
    public:
    swap1(int,int);
    swap1(swap1 &);
    void display();
};
swap1::swap1(swap1 &t)       //copy constructor
    {
        a=t.a;
        b=t.b;}
    swap1::swap1(int x,int y) //constructor
    {  cout<<endl<<"Enter the Value of X:";
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
 void swap1::display()//memberfunction
    {
        cout<<endl<<"Values After Swap: X="<<a<<"and Y="<<b;
    }
     main()
{
    int a1,b1;
    swap1 s(a1,b1);
    s.display();
    cout<<endl<<"Copy constructor called";
    swap1 copycon(s);   //copy constructor called
    copycon.display();
}