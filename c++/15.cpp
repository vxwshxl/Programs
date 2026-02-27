//15. Write a dynamic constructor in c++ to input a term and print the factorial of that term.

#include <iostream>

using namespace std;
class geeks {
	int* p;
	int f,r;

	public:
		geeks(int);
		void display();
};

geeks::geeks(int x) {	
	p = new int;
	*p = x;
	r=*p;
	f=1;
	while(*p!=0) {
		f=f*(*p);
		*p=*p-1;
	}
}

void geeks::display() {
	cout <<"Factorial of " <<r<<"="<<f<< endl;
}
     

int main() {
	int p1;
	cout<<endl<<"Enter the Term:";
	cin>>p1;
	geeks obj2 = geeks(p1);
	obj2.display();
}


// Output:
Enter the Term:5
Factorial of 5=120