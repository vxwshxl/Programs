// 55. Write the program in c++ input the values of base and exponent and print the power that term  without using predefined function..

#include<iostream>
using namespace std;

int main() {
    int n, p, c, a;
    cout<<endl<<"Enter number";
    cin>>n;
    cout<<"Enter base";
    cin>>p;
    c=0;
    a=1;
    while(p!=c) {
        a=a*n;
        c=c+1;
    }
    cout<<" power of"<<n<<" [base"<< p<<"] is="<<a;
    return 0;
}


// Output:
Enter number5
Enter base3
power of5 [base3] is=125