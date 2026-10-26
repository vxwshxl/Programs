// 7. Write a program in c to sort the elements using bucket sort and find its execution time using the time function.

/*
Algorithm: BucketSort(A, n)

1. Start
2. max <- largest element of A
3. For i <- 0 to (n-1) do
4.        size[i] <- 0
5. For i <- 0 to (n-1) do
6.        index <- (A[i]*n)/(max+1)
7.        bucket[index][size[index]] <- A[i]
8.        size[index] <- size[index]+1
9. For i <- 0 to (n-1) do
10.       sort bucket[i] using insertion sort
11. k <- 0
12. For i <- 0 to (n-1) do
13.       For j <- 0 to (size[i]-1) do
14.             A[k] <- bucket[i][j]
15.             k <- k+1
16. Print the sorted array A
17. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,j,k,key,index,max,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    clock_t start=clock();
    max=a[0];
    for(i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];

    int bucket[n][n],size[n];
    for(i=0;i<n;i++)
        size[i]=0;

    for(i=0;i<n;i++) {
        index=(a[i]*n)/(max+1);
        bucket[index][size[index]++]=a[i];
    }

    for(i=0;i<n;i++) {
        for(j=1;j<size[i];j++) {
            key=bucket[i][j];
            k=j-1;
            while(k>=0) {
                count++;
                if(bucket[i][k]>key) {
                    bucket[i][k+1]=bucket[i][k];
                    k--;
                }
                else
                    break;
            }
            bucket[i][k+1]=key;
        }
    }

    k=0;
    for(i=0;i<n;i++)
        for(j=0;j<size[i];j++)
            a[k++]=bucket[i][j];
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter bucket sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: average O(n+k), worst O(n^2)");
    printf("\nSpace complexity: O(n^2)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After bucket sorting:	8	14	19	27	35	42
// Number of comparisons:1
// Time taken:0.000002 seconds
// Time complexity: average O(n+k), worst O(n^2)
// Space complexity: O(n^2)
