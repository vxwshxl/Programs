// 2. Write an OOP in c++ to input a number and print the reverse of that number.

#include <iostream>
using namespace std;

class reverse{
    int n, r, s;

    public:
        void number(){
            cout<<endl<<"Enter a number: ";
            cin>>n;

            int p;
            p=n;
            s=0;

            for(;n!=0;){
                r=n%10;
                s=s*10+r;
                n=n/10;
            }

            cout<<endl<<"Reverse of "<<p<<" = "<<s;
        }
};

int main() {
    reverse r;
    r.number();
}