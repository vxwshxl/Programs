// 1. Write a program in c++ to search an element using linear search and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,key,pos=-1,count=0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to search:";
    cin>>key;

    clock_t start=clock();
    for(i=0;i<n;i++) {
        count++;
        if(a[i]==key) {
            pos=i;
            break;
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(pos==-1)
        cout<<endl<<key<<" is not found";
    else
        cout<<endl<<key<<" is found at position "<<pos+1;
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: best case O(1), worst case O(n)";
    cout<<endl;
}


// Output:
// Enter the number of elements:6
// Enter the elements:14 27 8 35 19 42
// Enter the element to search:35
//
// 35 is found at position 4
// Number of comparisons:4
// Time taken:0.000001 seconds
// Time complexity: best case O(1), worst case O(n)
