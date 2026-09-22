// 12. Write a program in c++ to find the minimum number of scalar multiplications needed for matrix chain multiplication using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int s[20][20];

void printOrder(int i,int j) {
    if(i==j) {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    printOrder(i,s[i][j]);
    printOrder(s[i][j]+1,j);
    cout<<")";
}

int main() {
    int n,i,j,k,l,count=0;
    cout<<"Enter the number of matrices:";
    cin>>n;
    int p[n+1];
    cout<<"Enter the "<<n+1<<" dimensions (matrix i is p[i-1] x p[i]):";
    for(i=0;i<=n;i++)
        cin>>p[i];
    int m[20][20];

    clock_t start=clock();
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++) {
        for(i=1;i<=n-l+1;i++) {
            j=i+l-1;
            m[i][j]=999999999;
            for(k=i;k<j;k++) {
                count++;
                int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<m[i][j]) {
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Cost table:";
    for(i=1;i<=n;i++) {
        cout<<endl;
        for(j=1;j<=n;j++)
            if(j<i)
                cout<<"\t-";
            else
                cout<<"\t"<<m[i][j];
    }
    cout<<endl<<"Minimum number of multiplications:"<<m[1][n];
    cout<<endl<<"Optimal parenthesization:";
    printOrder(1,n);
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n^3)";
    cout<<endl;
}


// Output:
// Enter the number of matrices:4
// Enter the 5 dimensions (matrix i is p[i-1] x p[i]):5 4 6 2 7
//
// Cost table:
// 	0	120	88	158
// 	-	0	48	104
// 	-	-	0	84
// 	-	-	-	0
// Minimum number of multiplications:158
// Optimal parenthesization:((A1(A2A3))A4)
// Number of comparisons:10
// Time taken:0.000006 seconds
// Time complexity: O(n^3)
