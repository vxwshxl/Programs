// 14. Write a program in c++ to find the length of the longest common subsequence (LCS) of two sequences using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int c[50][50];
char b[50][50];

int main() {
    char x[50],y[50];
    int m=0,n=0,i,j,count=0;
    cout<<"Enter the first sequence X:";
    cin>>x;
    cout<<"Enter the second sequence Y:";
    cin>>y;
    while(x[m]!='\0')
        m++;
    while(y[n]!='\0')
        n++;

    clock_t start=clock();
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            count++;
            if(x[i-1]==y[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1]) {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"c[i,j] table (D=diagonal, U=up, L=left):"<<endl<<"\t\t";
    for(j=0;j<n;j++)
        cout<<y[j]<<"\t";
    for(i=0;i<=m;i++) {
        cout<<endl;
        if(i==0)
            cout<<"\t";
        else
            cout<<x[i-1]<<"\t";
        for(j=0;j<=n;j++)
            if(i==0 || j==0)
                cout<<c[i][j]<<"\t";
            else
                cout<<c[i][j]<<b[i][j]<<"\t";
    }
    cout<<endl<<"Length of LCS:"<<c[m][n];
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(mn)";
    cout<<endl;
}


// Output:
// Enter the first sequence X:ABCBDAB
// Enter the second sequence Y:BDCABA
//
// c[i,j] table (D=diagonal, U=up, L=left):
// 		B	D	C	A	B	A
// 	0	0	0	0	0	0	0
// A	0	0U	0U	0U	1D	1L	1D
// B	0	1D	1L	1L	1U	2D	2L
// C	0	1U	1U	2D	2L	2U	2U
// B	0	1D	1U	2U	2U	3D	3L
// D	0	1U	2D	2U	2U	3U	3U
// A	0	1U	2U	2U	3D	3U	4D
// B	0	1D	2U	2U	3U	4D	4U
// Length of LCS:4
// Number of comparisons:42
// Time taken:0.000003 seconds
// Time complexity: O(mn)
