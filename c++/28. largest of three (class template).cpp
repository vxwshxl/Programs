// 28. Write the class template to print the largest of 3 different input integer numbers and float numbers using ternary operators.

#include<iostream>
using namespace std;

template<class Test1> Test1 FindLarge(Test1 a,Test1 b, Test1 c) {
    int max1=(a>b)?(a>c)?a:c:(b>c)?b:c;
    return max1;
}

int main() {
    int a, b, c, large;
    double a1, b1, c1, large1;
    cout<<endl<<"Enter three Different Numbers:";
    cin>>a>>b>>c;
    large=FindLarge(a,b,c);
    cout<<endl<<"Largest number="<<large;
    cout<<endl<<"Enter three Different float Numbers:";
    cin>>a1>>b1>>c1;
    large1=FindLarge(a1,b1,c1);
    cout<<endl<<"Largest number="<<large1;
}


// Output:
Enter three Different Numbers:5
6
7

Largest number=7
Enter three Different float Numbers:6.7
45.5
-67.8

Largest number=45