// 3. Write a function in c++ to input a term and print the sum of the digit of that term.

#include <iostream>
using namespace std;

int sum_of_digits(int n){
    int digit, sum;
    sum = 0;
    while(n != 0){
        digit = n % 10;
        sum = sum + digit;
        n = n / 10;
    }
    return sum;
}

int main() {
    int number, digits_sum;
    cout<<"Enter Positive Integer within the range: ";
    cin>>number;
    digits_sum = sum_of_digits(number);
    cout<<"Sum of digits of "<<number<<" is "<< digits_sum;
    
    return 0;
}


// Output:
Enter Positive Integer within the range: 123
Sum of digits of 123 is 6