// 10. Write a program in c++ to find the fibonacci series using recursion and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int calls=0;

int fib(int n) {
    calls++;
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main() {
    int n,i;
    cout<<"Enter the number of terms:";
    cin>>n;

    clock_t start=clock();
    cout<<endl<<"Fibonacci series:";
    for(i=0;i<n;i++)
        cout<<"\t"<<fib(i);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Number of function calls:"<<calls;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(2^n)";
    cout<<endl;
}


// Output:
// Enter the number of terms:10
//
// Fibonacci series:	0	1	1	2	3	5	8	13	21	34
// Number of function calls:276
// Time taken:0.000025 seconds
// Time complexity: O(2^n)
