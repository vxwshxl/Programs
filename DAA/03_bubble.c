// 3. Write a program in c to sort the elements using bubble sort and find its execution time using the time function.

/*
Algorithm: BubbleSort(A, n)

1. Start
2. For i <- 0 to (n-2) do
3.        For j <- 0 to (n-i-2) do
4.              if A[j] > A[j+1] then
5.                    temp <- A[j]
6.                    A[j] <- A[j+1]
7.                    A[j+1] <- temp
8. Print the sorted array A
9. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,j,temp,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    clock_t start=clock();
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            count++;
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter bubble sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n^2)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After bubble sorting:	8	14	19	27	35	42
// Number of comparisons:15
// Time taken:0.000005 seconds
// Time complexity: O(n^2)
