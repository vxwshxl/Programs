// 11. Write a program in c++ to find the fibonacci series using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,count=0;
    cout<<"Enter the number of terms:";
    cin>>n;
    int f[n];

    clock_t start=clock();
    for(i=0;i<n;i++) {
        count++;
        if(i<=1)
            f[i]=i;
        else
            f[i]=f[i-1]+f[i-2];
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Fibonacci series:";
    for(i=0;i<n;i++)
        cout<<"\t"<<f[i];
    cout<<endl<<"Number of iterations:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n)";
    cout<<endl;
}


// Output:
// Enter the number of terms:10
//
// Fibonacci series:	0	1	1	2	3	5	8	13	21	34
// Number of iterations:10
// Time taken:0.000004 seconds
// Time complexity: O(n)
