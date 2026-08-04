// 3. Write a program in c++ to sort the elements using bubble sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,j,temp,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];

    clock_t start=clock();
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            count++;
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"After bubble sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n^2)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After bubble sorting:	8	14	19	27	35	42
// Number of comparisons:15
// Time taken:0.000002 seconds
// Time complexity: O(n^2)
