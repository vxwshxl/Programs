// 32. Write a program in c++ to input a decimal number and print the binary equivalent of that number with operator overloading.



#include<iostream>    
using namespace std;    

class Test {    
    int d,b,r,i;
    public:
        Test(int d1) {
            d=d1;
        }

    Test operator++() {
        b=0;i=1;
        while(d!=0) {
            r=d%2;
            d=d/2;
            b=b+r*i;
            i=i*10;
        }
        
        return b;
    }

    void print();
};

void Test::print() {
    cout<<endl<<" Binary number is:"<<b;
}

int main() {
    int dd;
    cout<<endl<<"Enter a decimal number:";
    cin>>dd;
    Test t1(dd);
    ++t1;
    t1.print();
}


// Output:
Enter a decimal number:15

Binary number is:1111