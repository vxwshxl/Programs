// 2. Write a program in c++ to search an element using binary search and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,key,low,high,mid,pos=-1,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements in ascending order:";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to search:";
    cin>>key;

    clock_t start=clock();
    low=0;
    high=n-1;
    while(low<=high) {
        count++;
        mid=(low+high)/2;
        if(a[mid]==key) {
            pos=mid;
            break;
        }
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(pos==-1)
        cout<<endl<<key<<" is not found";
    else
        cout<<endl<<key<<" is found at position "<<pos+1;
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: best case O(1), worst case O(log n)";
    cout<<endl;
}


// Output:
// Enter the number of elements:7
// Enter the elements in ascending order:8 14 19 27 35 42 56
// Enter the element to search:42
//
// 42 is found at position 6
// Number of comparisons:2
// Time taken:0.000001 seconds
// Time complexity: best case O(1), worst case O(log n)
