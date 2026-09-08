// 5. Write a program in c++ to sort the elements using merge sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

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

void mergeSort(int a[],int low,int high,int &count) {
    if(low<high) {
        int mid=(low+high)/2;
        mergeSort(a,low,mid,count);
        mergeSort(a,mid+1,high,count);
        merge(a,low,mid,high,count);
    }
}

int main() {
    int n,i,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];

    clock_t start=clock();
    mergeSort(a,0,n-1,count);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"After merge sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n log n)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After merge sorting:	8	14	19	27	35	42
// Number of comparisons:11
// Time taken:0.000003 seconds
// Time complexity: O(n log n)
