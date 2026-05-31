//9. Write a member function in c++ to input a term and print the multiplication table of that term where input message is printed in underline

#include<iostream>
#define U "\033[4m"
#define CU "\033[0m"
using namespace std;

class multiplication {
    int n,m,i;
    public:
        void gettable();
};

void multiplication::gettable() {
    cout<<endl<<U<<"Enter the Terms:"<<CU;
    cin>>n;
    i=1;
    while(i<=10) {
        m=i*n;
        cout<<endl<<n<<"x"<<i<<"="<<m;
        i++;
    }
}

int main() {
    multiplication ml;
    ml.gettable();
}


// Output:
Enter the Terms:6

6x1=6
6x2=12
6x3=18
6x4=24
6x5=30
6x6=36
6x7=42
6x8=48
6x9=54
6x10=60