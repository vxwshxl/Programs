// 35. Write a program  in c++ to print the sum of nth terms using static data members with static member functions.

#include <iostream>
using namespace std;

class Box {
    private:
	    static int sum;
	public:
	    static void print() {
            int i,n;
            cout<<endl<<"Enter the Terms:";
            cin>>n;
            for(i=1;i<=n;i++) {
                sum=sum+i;
            }
            cout << "The value of the length is: " << sum << endl;
	    }
};

// initialize the static data members

int Box :: sum = 0;
int main() {
    Box b;
	cout << "Static member function is called through Object name: " << endl;
	b.print();
	cout << "\nStatic member function is called through Class name:[2 times of sum of terms] " << endl;
	Box::print();	
}


// Output:
Static member function is called through Object name:

Enter the Terms:6
The value of the length is: 21

Static member function is called through Class name:[2 times of sum of terms]

Enter the Terms:4
The value of the length is: 31