// 4. Write a program in c to sort the elements using selection sort and find its execution time using the time function.

/*
Algorithm: SelectionSort(A, n)

1. Start
2. For i <- 0 to (n-2) do
3.        min <- i
4.        For j <- i+1 to (n-1) do
5.              if A[j] < A[min] then
6.                    min <- j
7.        temp <- A[i]
8.        A[i] <- A[min]
9.        A[min] <- temp
10. Print the sorted array A
11. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,j,min,temp,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    clock_t start=clock();
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) {
            count++;
            if(a[j]<a[min])
                min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter selection sorting:");
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
// After selection sorting:	8	14	19	27	35	42
// Number of comparisons:15
// Time taken:0.000006 seconds
// Time complexity: O(n^2)
