// 8. Write a program in c to sort the elements using quick sort and find its execution time using the time function.

/*
Algorithm: QuickSort(A, low, high)

1. Start
2. If (low < high) then
3.        p <- Partition(A, low, high)
4.        QuickSort(A, low, p-1)
5.        QuickSort(A, p+1, high)
6. Stop

Algorithm: Partition(A, low, high)

1. pivot <- A[high]
2. i <- low-1
3. For j <- low to (high-1) do
4.        if A[j] <= pivot then
5.              i <- i+1
6.              swap A[i] and A[j]
7. swap A[i+1] and A[high]
8. Return i+1
*/

#include<stdio.h>
#include<time.h>

int count=0;

int partition(int a[],int low,int high) {
    int pivot=a[high];
    int i=low-1,j,temp;

    for(j=low;j<high;j++) {
        count++;
        if(a[j]<=pivot) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}

void quickSort(int a[],int low,int high) {
    if(low<high) {
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
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
    quickSort(a,0,n-1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nAfter quick sorting:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n log n) average, O(n^2) worst");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After quick sorting:	8	14	19	27	35	42
// Number of comparisons:9
// Time taken:0.000006 seconds
// Time complexity: O(n log n) average, O(n^2) worst
