// 15. Write a program in c++ to print the longest common subsequence (LCS) of two sequences using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int c[50][50];
char b[50][50];
char x[50],y[50];
int calls=0;

void printLCS(int i,int j) {
    calls++;
    if(i==0 || j==0)
        return;
    if(b[i][j]=='D') {
        printLCS(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]=='U')
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}

int main() {
    int m=0,n=0,i,j;
    cout<<"Enter the first sequence X:";
    cin>>x;
    cout<<"Enter the second sequence Y:";
    cin>>y;
    while(x[m]!='\0')
        m++;
    while(y[n]!='\0')
        n++;

    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
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

    cout<<endl<<"Length of LCS:"<<c[m][n];
    cout<<endl<<"LCS:";
    clock_t start=clock();
    printLCS(m,n);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Number of recursive calls:"<<calls;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(m+n)";
    cout<<endl;
}


// Output:
// Enter the first sequence X:ABCBDAB
// Enter the second sequence Y:BDCABA
//
// Length of LCS:4
// LCS:BCBA
// Number of recursive calls:9
// Time taken:0.000001 seconds
// Time complexity: O(m+n)
