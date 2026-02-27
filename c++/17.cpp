//17. Write a program in c++ to input a term and print the binary equivalent of that term without using main function

#include<iostream>
#define decibin main
using namespace std;

int decibin() {
    int n,p,bi,i,r;

    bi=0;
    i=1;
    cout<<"Enter the Term:";
    cin>>n;
    p=n;

    while(n!=0) {
        r=n%2;
        n=n/2;
        bi=bi+r*i;
        i=i*10;
    }

    cout<<endl<<"Binary equivalent of"<<p<<"="<<bi;
    return 0;
}


// Output:
Enter the Term:65

Binary equivalent of65=1000001