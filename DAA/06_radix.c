// 6. Write a program in c to sort the elements using radix sort and find its execution time using the time function.

/*
Algorithm: RadixSort(A, n)

1. Start
2. max <- largest element of A
3. exp <- 1
4. While (max/exp > 0) do
5.        CountSort(A, n, exp)
6.        exp <- exp*10
7. Print the sorted array A
8. Stop

Algorithm: CountSort(A, n, exp)

1. For i <- 0 to 9 do
2.        bucket[i] <- 0
3. For i <- 0 to (n-1) do
4.        d <- (A[i]/exp) mod 10
5.        bucket[d] <- bucket[d]+1
6. For i <- 1 to 9 do
7.        bucket[i] <- bucket[i]+bucket[i-1]
8. For i <- (n-1) down to 0 do
9.        d <- (A[i]/exp) mod 10
10.       bucket[d] <- bucket[d]-1
11.       output[bucket[d]] <- A[i]
12. For i <- 0 to (n-1) do
13.       A[i] <- output[i]
14. Return
*/

#include<stdio.h>
#include<time.h>

int count=0;

void countSort(int a[],int n,int exp) {
    int output[n],bucket[10],i;

    for(i=0;i<10;i++)
        bucket[i]=0;
    for(i=0;i<n;i++) {
        count++;
        bucket[(a[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
        bucket[i]=bucket[i]+bucket[i-1];
    for(i=n-1;i>=0;i--) {
        count++;
        output[--bucket[(a[i]/exp)%10]]=a[i];
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
}

int main() {
    int n,i,max,exp;
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
    for(exp=1;max/exp>0;exp=exp*10)
        countSort(a,n,exp);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter radix sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of operations:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(d*n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After radix sorting:	8	14	19	27	35	42
// Number of operations:24
// Time taken:0.000009 seconds
// Time complexity: O(d*n)
