// 2. Write a program in c to search an element using binary search and find its execution time using the time function.

/*
Algorithm: BinarySearch(A, n, x)

1. Start
2. low <- 0, high <- (n-1)
3. While (low <= high) do
4.        mid <- (low+high)/2
5.        if x == A[mid] then
6.              print "Element Found"
7.              exit
8.        else if A[mid] < x then
9.              low <- mid+1
10.       else
11.             high <- mid-1
12. If (low > high) then
13.        print "Element Not Found"
14. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,x,low,high,mid,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in ascending order:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search:");
    scanf("%d",&x);

    clock_t start=clock();
    low=0;
    high=n-1;
    while(low<=high) {
        count++;
        mid=(low+high)/2;
        if(x==a[mid])
            break;
        else if(a[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(low>high)
        printf("\n%d is not found",x);
    else
        printf("\n%d is found at position %d",x,mid+1);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: best case O(1), worst case O(log n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:7
// Enter the elements in ascending order:8 14 19 27 35 42 56
// Enter the element to search:42
//
// 42 is found at position 6
// Number of comparisons:2
// Time taken:0.000005 seconds
// Time complexity: best case O(1), worst case O(log n)
