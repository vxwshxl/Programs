// 5. Write a program in c++ to sort the elements using insertion sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,j,key,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];

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

    cout<<endl<<"After insertion sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: best case O(n), worst case O(n^2)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After insertion sorting:	8	14	19	27	35	42
// Number of comparisons:12
// Time taken:0.000004 seconds
// Time complexity: best case O(n), worst case O(n^2)
