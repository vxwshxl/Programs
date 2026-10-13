// 16. Write a program in c++ to solve the job sequencing with deadlines problem using the greedy method and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int p[50];

void merge(int a[],int low,int mid,int high,int &count) {
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

void mergeSort(int a[],int low,int high,int &count) {
    if(low<high) {
        int mid=(low+high)/2;
        mergeSort(a,low,mid,count);
        mergeSort(a,mid+1,high,count);
        merge(a,low,mid,high,count);
    }
}

int main() {
    int n,i,k,t,maxd=0,total=0,count=0;
    cout<<"Enter the number of jobs:";
    cin>>n;
    int d[n+1],order[n];
    cout<<"Enter the profits of "<<n<<" jobs:";
    for(i=1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter the deadlines of "<<n<<" jobs:";
    for(i=1;i<=n;i++) {
        cin>>d[i];
        if(d[i]>maxd)
            maxd=d[i];
    }
    int slot[maxd+1];

    clock_t start=clock();
    for(i=1;i<=n;i++)
        order[i-1]=i;
    for(t=1;t<=maxd;t++)
        slot[t]=0;
    mergeSort(order,0,n-1,count);
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

    cout<<endl<<"Jobs in decreasing order of profit:"<<endl<<"Job\tProfit\tDeadline";
    for(k=0;k<n;k++) {
        i=order[k];
        cout<<endl<<"J"<<i<<"\t"<<p[i]<<"\t"<<d[i];
    }
    cout<<endl<<"Job sequence:";
    for(t=1;t<=maxd;t++)
        if(slot[t]!=0)
            cout<<"\tJ"<<slot[t];
    cout<<endl<<"Maximum profit:"<<total;
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n^2)";
    cout<<endl;
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
// Time taken:0.000000 seconds
// Time complexity: O(n^2)
