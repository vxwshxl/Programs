
50.write the member function in c++ to  input the degree and term and print the sin(x) values of taylors series.
#include <iostream>
using namespace std;
class taylors
{
int i,n;
public:
void sinxvalue()
{
float xdeg,xrad,sum,term;
cout<<"Enter the value of x in degree: ";
cin>>xdeg;
cout<<"\nEnter the number of terms: ";
cin>>n;
xrad=xdeg*3.141592/180;
term=sum=xrad;
for(i=2;i<=n;i++)
{
term*=-(xrad*xrad)/((2*i-1)*(2*i-2));
sum+=term;
}
cout<<"\n sin("<<xdeg<<")= "<<sum<<endl;

}

};
int main()
{
taylors t1;
t1.sinxvalue();
}
output:
Enter the value of x in degree: 180

Enter the number of terms: 10

 sin(180)= 8.9477e-07