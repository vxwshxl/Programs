// 5. Write a program in c to sort the elements using insertion sort and find its execution time using the time function.

/*
Algorithm: InsertionSort(A, n)

1. Start
2. For i <- 1 to (n-1) do
3.        key <- A[i]
4.        j <- i-1
5.        While (j >= 0 and A[j] > key) do
6.              A[j+1] <- A[j]
7.              j <- j-1
8.        A[j+1] <- key
9. Print the sorted array A
10. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,j,key,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    clock_t start=clock();
    for(i=1;i<n;i++) {
        key=a[i];
        j=i-1;
        while(j>=0) {
            count++;
            if(a[j]>key) {
                a[j+1]=a[j];
                j--;
            }
            else
                break;
        }
        a[j+1]=key;
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter insertion sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: best case O(n), worst case O(n^2)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After insertion sorting:	8	14	19	27	35	42
// Number of comparisons:12
// Time taken:0.000005 seconds
// Time complexity: best case O(n), worst case O(n^2)
