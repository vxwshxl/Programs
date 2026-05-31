// 1. Write a program in c++ to input the value of dividend and divisor and print the quotient and remainder.

#include <iostream>
using namespace std;

int main(){
    int dividend, divisor, quotient, remainder;

    cout<<"Enter dividend: ";
    cin>>dividend;
    
    cout<<"Enter divisor: ";
    cin>>divisor;
    
    quotient = dividend / divisor;
    remainder = dividend % divisor;
    
    cout<<"Quotient: "<<quotient<<endl;
    cout<<"Remainder: "<<remainder<<endl;
    
    return 0;
}

// Output:
Enter dividend: 5
Enter divisor: 2
Quotient: 2
Remainder: 1