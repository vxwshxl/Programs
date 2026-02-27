// 18. Write a constructor in c++ to input a term and print the factorial of that term using destructor.

#include <iostream>
using namespace std;

class Test {
    int f,n,p;
    public:
        Test();
        ~Test();
};

Test::Test() {
    cout << "\n Enter the Term:";
    cin>>n;
    f=1;
    p=n;
    while(n!=0) {
        f=f*n;
        n=n-1;
    }
}

Test::~Test() {
    cout<<endl<<"using Destructor:";
    cout <<endl<<"Factorai of"<<p<<"="<<f;
}

main() {
    Test t;
}


// Output:
Enter the Term:6

using Destructor:
Factorai of6=720