// 33. Write a program in c++ to input a number and check whether it is a prime number or not.

#include<iostream>
using namespace std;

int main() {
    int n,i;
    bool f;
    f=false;
    cout<<endl<<"Enter a term:";
    cin>>n;
    i=2;
    while(i<n) {
        if(n%i==0) {
            f=true;
        }
        i++;
    }
    
    if(f)
        cout<<n<<"is not a prime number:";
    else {
        cout<<n<<"is a prime number:";
    }
}


// Output:
Enter a term:6
6is not a prime number:
fingers@fingers-B460M-GAMING-HD:$ ./a.out

Enter a term:7
7is a prime number: