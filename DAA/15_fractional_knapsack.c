// 15. Write a program in c to solve the fractional knapsack problem using the greedy method and find its execution time using the time function.

/*
Algorithm: FractionalKnapsack(v, w, n, W)

1. Start
2. For i <- 1 to n do
3.        r[i] <- v[i]/w[i]
4.        x[i] <- 0
5. Sort the items in decreasing order of r[i] (merge sort)
6. remaining <- W, total <- 0
7. For each item i in sorted order, while remaining > 0 do
8.        if w[i] <= remaining then
9.              x[i] <- 1
10.             remaining <- remaining - w[i]
11.       else
12.             x[i] <- remaining/w[i]
13.             remaining <- 0
14.       total <- total + x[i]*v[i]
15. print "Maximum value" total
16. Stop
*/

#include<stdio.h>
#include<time.h>

double r[50];
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
        if(r[left[i]]>=r[right[j]])
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
    int n,i,k;
    double W;
    printf("Enter the number of items:");
    scanf("%d",&n);
    double v[n+1],w[n+1],x[n+1];
    int order[n];
    printf("Enter the values of %d items:",n);
    for(i=1;i<=n;i++)
        scanf("%lf",&v[i]);
    printf("Enter the weights of %d items:",n);
    for(i=1;i<=n;i++)
        scanf("%lf",&w[i]);
    printf("Enter the capacity of the knapsack:");
    scanf("%lf",&W);

    clock_t start=clock();
    for(i=1;i<=n;i++) {
        r[i]=v[i]/w[i];
        x[i]=0;
        order[i-1]=i;
    }
    mergeSort(order,0,n-1);
    double remaining=W,total=0;
    for(k=0;k<n && remaining>0;k++) {
        i=order[k];
        count++;
        if(w[i]<=remaining) {
            x[i]=1;
            remaining=remaining-w[i];
        }
        else {
            x[i]=remaining/w[i];
            remaining=0;
        }
        total=total+x[i]*v[i];
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nItems in decreasing order of value/weight:\nItem\tValue\tWeight\tv/w\tFraction");
    for(k=0;k<n;k++) {
        i=order[k];
        printf("\n%d\t%g\t%g\t%g\t%g",i,v[i],w[i],r[i],x[i]);
    }
    printf("\nMaximum value:%g",total);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n log n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of items:4
// Enter the values of 4 items:10 40 30 50
// Enter the weights of 4 items:5 4 6 3
// Enter the capacity of the knapsack:10
//
// Items in decreasing order of value/weight:
// Item	Value	Weight	v/w	Fraction
// 4	50	3	16.6667	1
// 2	40	4	10	1
// 3	30	6	5	0.5
// 1	10	5	2	0
// Maximum value:105
// Number of comparisons:8
// Time taken:0.000006 seconds
// Time complexity: O(n log n)
