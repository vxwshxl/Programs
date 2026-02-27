// 20. Write a program in c++ to input the values of numerator and denominator and check if denominator is zero exception is caught  and print using exception handling otherwise it print the quotient.

#include<iostream>
using namespace std;

int main() {
    try {
        int n;
        int d;
        int res;
        cout<<endl<<"Enter the Numerator";
        cin>>n;
        cout<<endl<<"Enter the denominator";
        cin>>d;
        if (d == 0) {
            throw runtime_error("Division by zero not allowed!");
        }
        res = n / d;
        cout << "Quotient after division: " << res << endl;
    }
    catch (const exception& e) {
        cout << "Exception " << e.what() << endl;
    }    
}


// Output:
Enter the Numerator6

Enter the denominator3
Quotient after division: 2