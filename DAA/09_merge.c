// 9. Write a program in c to sort the elements using merge sort and find its execution time using the time function.

/*
Algorithm: MergeSort(A, low, high)

1. Start
2. If (low < high) then
3.        mid <- (low+high)/2
4.        MergeSort(A, low, mid)
5.        MergeSort(A, mid+1, high)
6.        Merge(A, low, mid, high)
7. Stop

Algorithm: Merge(A, low, mid, high)

1. n1 <- mid-low+1, n2 <- high-mid
2. Copy A[low..mid] into L[0..n1-1] and A[mid+1..high] into R[0..n2-1]
3. i <- 0, j <- 0, k <- low
4. While (i < n1 and j < n2) do
5.        if L[i] <= R[j] then
6.              A[k] <- L[i], i <- i+1
7.        else
8.              A[k] <- R[j], j <- j+1
9.        k <- k+1
10. Copy the remaining elements of L and R into A
11. Return
*/

#include<stdio.h>
#include<time.h>

int count=0;

void merge(int a[],int low,int mid,int high) {
    int n1=mid-low+1,n2=high-mid;
    int left[n1],right[n2];
    int i,j,k;

    for(i=0;i<n1;i++)
        left[i]=a[low+i];
    for(j=0;j<n2;j++)
        right[j]=a[mid+1+j];

    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2) {
        count++;
        if(left[i]<=right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
    while(i<n1)
        a[k++]=left[i++];
    while(j<n2)
        a[k++]=right[j++];
}

void mergeSort(int a[],int low,int high) {
    if(low<high) {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    clock_t start=clock();
    mergeSort(a,0,n-1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter merge sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n log n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After merge sorting:	8	14	19	27	35	42
// Number of comparisons:11
// Time taken:0.000008 seconds
// Time complexity: O(n log n)
