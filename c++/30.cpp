// 30. Write the constructors in c++ to input the term and generate the fibonacci series of that term using the concept of multilevel inheritance
#include<iostream>
using namespace std;
class fibo1
{
protected:
int a,n;
public:
fibo1();
};
fibo1::fibo1()
{
cout<<endl<<"Enter a term:";
cin>>n;
a=0;
cout<<endl<<"Fibonacci Series are:";
cout<<a;
}
class fibo2:public fibo1
{
protected:
int b;
public:
fibo2();
};
fibo2::fibo2()
{
b=1;
cout<<"\t"<<b;
}
class fibo3:public fibo2
{
int i,c;
public:
fibo3();
};
fibo3::fibo3()
{
i=2;
while(i<n)
{
c=a+b;
i=i+1;
cout<<"\t"<<c;
a=b;
b=c;
}
}
main()
{
fibo3 f3;
}
output:
Enter a term:6

Fibonacci Series are:0	1	1	2	3	5
