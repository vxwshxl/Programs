// 39. Write a member function in c++ to input a term and print the sum of the digit of that term

#include<iostream>
using namespace std;

class sumdigit {
    int n,s,r;
    public:
    void calculate();
};

void sumdigit::calculate() {
    cout<<endl<<"Enter the Terms:";
    cin>>n;
    int p;
    p=n;
    s=0;
    while(n!=0) {
        r=n%10;
        s=s+r;
        n=n/10;
    }

    cout<<endl<<"sum of the digit of"<<p<<"="<<s;
}

int main() {
    sumdigit s1;
    s1.calculate();
}


// Output:
Enter the Terms:4567

sum of the digit of4567=22