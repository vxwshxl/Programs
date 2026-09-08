// 6. Write a program in c++ to sort the elements using quick sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int partition(int a[],int low,int high,int &count) {
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

void quickSort(int a[],int low,int high,int &count) {
    if(low<high) {
        int p=partition(a,low,high,count);
        quickSort(a,low,p-1,count);
        quickSort(a,p+1,high,count);
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
    quickSort(a,0,n-1,count);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"After quick sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n log n) average, O(n^2) worst";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After quick sorting:	8	14	19	27	35	42
// Number of comparisons:9
// Time taken:0.000005 seconds
// Time complexity: O(n log n) average, O(n^2) worst
