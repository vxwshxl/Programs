// 10. Write a program in c to find the fibonacci series using recursion and find its execution time using the time function.

/*
Algorithm: Fib(n)

1. Start
2. If (n <= 1) then
3.        Return n
4. Return Fib(n-1) + Fib(n-2)
5. Stop

Algorithm: FibonacciSeries(n)

1. Start
2. For i <- 0 to (n-1) do
3.        print Fib(i)
4. Stop
*/

#include<stdio.h>
#include<time.h>

int calls=0;

int fib(int n) {
    calls++;
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main() {
    int n,i;
    printf("Enter the number of terms:");
    scanf("%d",&n);

    clock_t start=clock();
    printf("\nFibonacci series:");
    for(i=0;i<n;i++)
        printf("\t%d",fib(i));
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nNumber of function calls:%d",calls);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(2^n)");
    printf("\nSpace complexity: O(n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of terms:10
//
// Fibonacci series:	0	1	1	2	3	5	8	13	21	34
// Number of function calls:276
// Time taken:0.000009 seconds
// Time complexity: O(2^n)
// Space complexity: O(n)
