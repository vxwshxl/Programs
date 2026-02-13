// 7. Write a parameterized constructor in c++ to input a term and print the factorial of that term.

#include <iostream>
using namespace std;

class factorial{
    int n, f, p;
    
    public:
        factorial(int n1, int f1){
            n=n1;
            f=f1;
            
            cout<<endl<<"Enter a term: ";
            cin>>n;
            
            p=n;
            f=1;
            for(;n!=0;){
                f=f*n;
                n=n-1;
            }
            
            cout<<endl<<"Factorial of "<<p<<" = "<<f;
        }
};

int main(){
    int m, s;
    factorial f2(m,s);
}