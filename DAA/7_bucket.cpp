// 7. Write a program in c++ to sort the elements using bucket sort and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,j,k,key,index,max,count=0;
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

    int bucket[n][n],size[n];
    for(i=0;i<n;i++)
        size[i]=0;

    for(i=0;i<n;i++) {
        index=(a[i]*n)/(max+1);
        bucket[index][size[index]++]=a[i];
    }

    for(i=0;i<n;i++) {
        for(j=1;j<size[i];j++) {
            key=bucket[i][j];
            k=j-1;
            while(k>=0) {
                count++;
                if(bucket[i][k]>key) {
                    bucket[i][k+1]=bucket[i][k];
                    k--;
                }
                else
                    break;
            }
            bucket[i][k+1]=key;
        }
    }

    k=0;
    for(i=0;i<n;i++)
        for(j=0;j<size[i];j++)
            a[k++]=bucket[i][j];
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"After bucket sorting:";
    for(i=0;i<n;i++)
        cout<<"\t"<<a[i];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: average O(n+k), worst O(n^2)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:42 8 27 14 35 19
//
// After bucket sorting:	8	14	19	27	35	42
// Number of comparisons:1
// Time taken:0.000005 seconds
// Time complexity: average O(n+k), worst O(n^2)
