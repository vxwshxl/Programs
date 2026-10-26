// 16. Write a program in c to solve the job sequencing with deadlines problem using the greedy method and find its execution time using the time function.

/*
Algorithm: JobSequencing(p, d, n)

1. Start
2. maxd <- largest deadline
3. For t <- 1 to maxd do
4.        slot[t] <- 0
5. Sort the jobs in decreasing order of profit p[i] (merge sort)
6. total <- 0
7. For each job i in sorted order do
8.        For t <- d[i] down to 1 do
9.              if slot[t] == 0 then
10.                   slot[t] <- i
11.                   total <- total + p[i]
12.                   break
13. print the jobs in slot[1..maxd] and total
14. Stop
*/

#include<stdio.h>
#include<time.h>

int p[50];
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
        if(p[left[i]]>=p[right[j]])
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
    int n,i,k,t,maxd=0,total=0;
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    int d[n+1],order[n];
    printf("Enter the profits of %d jobs:",n);
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter the deadlines of %d jobs:",n);
    for(i=1;i<=n;i++) {
        scanf("%d",&d[i]);
        if(d[i]>maxd)
            maxd=d[i];
    }
    int slot[maxd+1];

    clock_t start=clock();
    for(i=1;i<=n;i++)
        order[i-1]=i;
    for(t=1;t<=maxd;t++)
        slot[t]=0;
    mergeSort(order,0,n-1);
    for(k=0;k<n;k++) {
        i=order[k];
        for(t=d[i];t>=1;t--) {
            count++;
            if(slot[t]==0) {
                slot[t]=i;
                total=total+p[i];
                break;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nJobs in decreasing order of profit:\nJob\tProfit\tDeadline");
    for(k=0;k<n;k++) {
        i=order[k];
        printf("\nJ%d\t%d\t%d",i,p[i],d[i]);
    }
    printf("\nJob sequence:");
    for(t=1;t<=maxd;t++)
        if(slot[t]!=0)
            printf("\tJ%d",slot[t]);
    printf("\nMaximum profit:%d",total);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n^2)");
    printf("\nSpace complexity: O(n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of jobs:5
// Enter the profits of 5 jobs:100 19 27 25 15
// Enter the deadlines of 5 jobs:2 1 2 1 3
//
// Jobs in decreasing order of profit:
// Job	Profit	Deadline
// J1	100	2
// J3	27	2
// J4	25	1
// J2	19	1
// J5	15	3
// Job sequence:	J3	J1	J5
// Maximum profit:142
// Number of comparisons:14
// Time taken:0.000003 seconds
// Time complexity: O(n^2)
// Space complexity: O(n)
