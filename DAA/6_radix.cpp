// 6. Write a program in c++ to sort the elements using radix sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

void countSort(int a[],int n,int exp,int &count) {
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
    int n,i,max,exp,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];

    clock_t start=clock();
    max=a[0];
    for(i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];
    for(exp=1;max/exp>0;exp=exp*10)
        countSort(a,n,exp,count);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"After radix sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of operations:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(d*n)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After radix sorting:	8	14	19	27	35	42
// Number of operations:24
// Time taken:0.000005 seconds
// Time complexity: O(d*n)
