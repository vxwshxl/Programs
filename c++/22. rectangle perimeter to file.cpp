// 22. Write a program in c++ to input the values of length and breadth and print the perimeter of the rectangle using a file name student.doc

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int l,b,a;
	cout<<"Enter the Length:";
	cin>>l;
    cout<<"Enter the Breadth:";
	cin>>b;
	a=2*(l+b);
    ofstream fout("student.doc");
    fout<<endl<<"perimeter of Rectangle"<<a; //write data to the file student
    fout.close();
    cout<<endl<<"perimeter of Rectangle"<<a;
}


// Output:
Enter the Length:2000
Enter the Breadth:3

perimeter of Rectangle4006
$ cat student.doc
perimeter of Rectangle4006