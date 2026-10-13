// 11. Write a program in c to find the fibonacci series using dynamic programming and find its execution time using the time function.

/*
Algorithm: FibonacciDP(n)

1. Start
2. For i <- 0 to (n-1) do
3.        if (i <= 1) then
4.              F[i] <- i
5.        else
6.              F[i] <- F[i-1] + F[i-2]
7. Print F[0..n-1]
8. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,count=0;
    printf("Enter the number of terms:");
    scanf("%d",&n);
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

    printf("\nFibonacci series:");
    for(i=0;i<n;i++)
        printf("\t%d",f[i]);
    printf("\nNumber of iterations:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of terms:10
//
// Fibonacci series:	0	1	1	2	3	5	8	13	21	34
// Number of iterations:10
// Time taken:0.000003 seconds
// Time complexity: O(n)
