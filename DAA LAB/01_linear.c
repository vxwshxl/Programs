// 1. Write a program in c to search an element using linear search and find its execution time using the time function.

/*
Algorithm: LinearSearch(A, n, x)

1. Start
2. For i <- 0 to (n-1) do
3.        if x == A[i] then
4.              print "Element Found"
5.              exit
6. If (i==n) then
7.         print "Element Not Found"
8. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,x,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search:");
    scanf("%d",&x);

    clock_t start=clock();
    for(i=0;i<n;i++) {
        count++;
        if(x==a[i])
            break;
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(i==n)
        printf("\n%d is not found",x);
    else
        printf("\n%d is found at position %d",x,i+1);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: best case O(1), worst case O(n)");
    printf("\nSpace complexity: O(1)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:14 27 8 35 19 42
// Enter the element to search:35
//
// 35 is found at position 4
// Number of comparisons:4
// Time taken:0.000003 seconds
// Time complexity: best case O(1), worst case O(n)
// Space complexity: O(1)
