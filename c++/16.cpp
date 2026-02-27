//16. Write a dynamic constructor in c++ to input a term and print the multiplication table of that term.

#include <iostream>
using namespace std;

class multi {
	int* p;
	int m,i;

	public:
		multi(int);
};	

multi::multi(int x) {
	p = new int;
	*p = x;
	i=1;
	cout<<endl<<"Multiplication Table of:"<<*p;
	
	while(i<=10) {
		m=i*(*p);
		cout<<endl<<*p<<"x"<<i<<"="<<m;
		i++;
	}
}

int main() {
	int p1;
	cout<<endl<<"Enter the Term:";
	cin>>p1;
	multi obj2 = multi(p1);
}


// Output:
Enter the Term:5

Multiplication Table of:5
5x1=5
5x2=10
5x3=15
5x4=20
5x5=25
5x6=30
5x7=35
5x8=40
5x9=45
5x10=50