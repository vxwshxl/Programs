// 25. Write the constructors in c++ to add the two input matrix using hierarchical inheritance using 2 dimensional arrays.
#include<iostream>
using namespace std;

class fstmatrix {
     protected:
     int a1[10][10];
     int n,m,i,j;
     int b1[10][10];
     int n1,m1;
     public:
          fstmatrix();
};

fstmatrix::fstmatrix() {
     cout<<endl<<"enter the number of Rows 1st matrix:";
     cin>>n;
     cout<<endl<<"enter the number of columns 1st matrix:";
     cin>>m;
     cout<<endl<<"Enter the Elements:";
     for(i=0;i<n;i++)
          for(j=0;j<m;j++)
               cin>>a1[i][j];
     cout<<endl<<"enter the number of Rows 2nd matrix:";
     cin>>n1;
     cout<<endl<<"enter the number of columns 2nd matrix:";
     cin>>m1;
     cout<<endl<<"Enter the Elements:";
     for(i=0;i<n1;i++)
          for(j=0;j<m1;j++)
               cin>>b1[i][j];
}

class sndmatrix:public fstmatrix {
     public:
          sndmatrix();
};

sndmatrix::sndmatrix() {
     cout<<endl<<"Hybrid Inheritance:";
}

class thrdmatrix: public fstmatrix {
     int c1[10][10];
     public:
     thrdmatrix();
};

thrdmatrix::thrdmatrix() {
     c1[i][j]=0;
     for(i=0;i<=n;i++) {
          for(j=0;j<=m;j++) {
               c1[i][j]=a1[i][j]+b1[i][j];
          }
     }
     cout<<endl<<"After Addition:";
     for(i=0;i<n;i++) {
          cout<<endl;
          for(j=0;j<m;j++) {
               cout<<"\t"<<c1[i][j];
          }
     }
}

int main()
{
thrdmatrix fs;
}


// Output:
enter the number of Rows 1st matrix:2

enter the number of columns 1st matrix:3

Enter the Elements:1
2
3
4
5
6

enter the number of Rows 2nd matrix:2

enter the number of columns 2nd matrix:3

Enter the Elements:6
7
8
9
10
11

After Addition:
	7	9	11
	13	15	17