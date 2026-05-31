// 42. Write the template function to input a number and check whether it is an odd number or even number

#include<iostream>
using namespace std;
template<typename oe>

oe oddeven(oe n) {
    if(n%2==0)
        cout<<endl<<"it is an Even number->";
    else {
        cout<<endl<<"it is an odd number->";
    }

    return n;
}

int main() {
    int n1;
    cout<<endl<<"Enter the value of N:";
    cin>>n1;
    cout<<oddeven<int>(n1)<<endl;
}


// Output:
Enter the value of N:6

it is an Even number->6
