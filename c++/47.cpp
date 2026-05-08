// 47. Write a program in c++ to input a term and print the the following pattern using virtual base class
/*
n=5
*****
****
***
**
*
*/

#include <iostream>
using namespace std;

class shape1 {
    public:
        int i,j,n;
        shape1() {
            cout<<"Enter the number of Rows:";
            cin>>n;
            for(i=n;i>=1;i--) {
                for(j=1;j<=i;j++) {
                    cout<<"* ";
                }
                cout<<endl;
            }
        }
};
class shape2 : public virtual shape1 {
};
class shape3 : public virtual shape1 {
};
class shape4 : public shape2, public shape3 {
};

int main()
{
	shape4 s4;  
	cout << "Total term=" << s4.n << endl; 	
}


// Output:
Enter the number of Rows:7
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *
* *
*
Total term=7