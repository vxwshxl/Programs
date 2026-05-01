// 43. Write the template function to print the sum of 1st nth term and find the duplicate elements from an array list using template function overloading.

#include <iostream>
using namespace std;
template <class T>

void display(T t1,T i) {
    int c;
    c=0;
    cout<<endl<<"Enter the no of elements:";
    cin>>t1;
    for(i=0;i<t1;i++) {
        c=c+i;;
    }
    cout << "Sum of 1st nth term" << c;
}

void display(int t1) {
    int i,j;
    cout<<endl<<"Entter the no of elements:";
    cin>>t1;
    int a[t1];
    cout<<endl<<"Enter the Elements";
    for(i=0;i<t1;i++) {
        cin>>a[i];
    }
    for(i=0;i<t1;i++) {
        for(j=i+1;j<t1;j++) {
            if(a[i]==a[j]) {
                cout<<endl<<"Duplicate Elements"<<a[i];	
            }
        }
    }
}

int main() {
    int a,b1,c1;
    display(b1,c1);
    display(a);
    return 0;
}

// Output:
Enter the no of elements:5
Sum of 1st nth term10
Entter the no of elements:5

Enter the Elements3
4
4
5
6

Duplicate Elements4