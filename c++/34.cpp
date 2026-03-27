// 34. write the constructor in c++ to input a term and check whether it is an armstrong number or not using the concept of single inheritance
#include<iostream>
#include<math.h>
using namespace std;
class armstrrong {
    protected:
        int n,m,p,r,s,c;
    public:
        armstrrong();
    };
class display:public armstrrong
    {
    protected:
    public:
        display();
    };
    armstrrong::armstrrong() {
    s=0;
    cout<<"Enter a number:";
    cin>>n;
    m=n;p=n;
    while(m!=0)
    {
        m=m/10;
        c=c+1;
    }
    while(n!=0)
    {
        r=n%10;
        s=s+pow(r,c);
        n=n/10;
    }
}

display::display() {
    if(s==p)
        cout<<p<<"is an Armstrong Number:";
    else
       cout<<p<<"is not an Armstrong Number:";
}

int main() {
    display dt;
}

/* output:
Enter a number:54748
54748is an Armstrong Number:*/