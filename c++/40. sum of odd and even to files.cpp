40. write the constructor in c++ to print the sum of odd numbers in student2.doc file  and print the sum of even numbers in student1.doc file.
#include<iostream>
#include<fstream>
using namespace std;

class someode {
    int i,ode,eve;
    public:
        someode();
};

someode::someode() {
    ode=0;
    eve=0;
    cout<<endl<<"some of odd and even numbers[1-50]";
    
    for(i=1;i<=50;i++) {
        if(i%2==0) {
            eve=i+eve;
        }
        else {
            ode=i+ode;
        }
    }

    ofstream fit("student1.doc");
    cout<<endl<<"even Total:"<<eve;
    fit<<endl<<"even Total:"<<eve;
    ofstream fout("student2.doc");
    fout<<endl<<"Ode Total:"<<ode;
    cout<<endl<<"Ode Total:"<<ode;
}

int main() {
    someode sd;
}


// Output:
some of odd and even numbers[1-50]
even Total:650
Ode Total:625
$cat student1.doc

even Total:650
$cat student2.doc

Ode Total:625