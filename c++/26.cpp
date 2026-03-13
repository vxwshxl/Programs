// 27. Write the constructors in c++ to transpose of an  input matrix using friend function with hybrid inheritance.

#include<iostream>
using namespace std;

class display;
class message {
    protected:
    public:
        message();
};

message::message() {
    cout<<endl<<"Matrix transpose:";
}

class matrix:public message {
    protected:
        int a[10][10];
        int n,m,i,j;
    public:
        matrix();
        friend void displaymat(matrix,display);
};

matrix::matrix() {
    cout<<endl<<"Enter the Rows:";
    cin>>n;
    cout<<endl<<"Enter the Columns:";
    cin>>m;
    cout<<endl<<"Enter the Elements:";
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
}

class display:public message {
    public:
        friend void displaymat(matrix,display);
};

void displaymat(matrix m1,display n1) {
    int i,j;
    cout<<endl<<"Matrix is:";
    for(i=0;i<m1.n;i++) {
        cout<<endl;
        for(j=0;j<m1.m;j++) {
            cout<<"\t"<<m1.a[i][j];
        }
    }
}

class transpose:public matrix,public display {
    int tr[10][10];
    public:
    transpose();
};

transpose::transpose() {
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            tr[j][i]=a[i][j];
    for(i=0;i<m;i++) {
        cout<<endl;
        for(j=0;j<n;j++) {
            cout<<"\t"<<tr[i][j];
        }
    }
}

int main() {
    transpose tr;
    matrix mr;
    display dr;
    displaymat(mr,dr);
}

// Output:
Matrix transpose:
Enter the Rows:3

Enter the Columns:3

Enter the Elements:1
2
3
4
5
6
7
8
9

Matrix transpose:
	1	4	7
	2	5	8
	3	6	9
Matrix transpose:
Enter the Rows:2

Enter the Columns:3

Enter the Elements:1
2
3
4
5
6

Matrix transpose:
Matrix is:
	1	2	3
	4	5	6