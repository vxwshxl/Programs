// 18. Write a program in c++ to solve the N-Queen problem using backtracking and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int x[20],first[20];
int n,solutions=0,comp=0;

int place(int k,int i) {
    for(int j=1;j<k;j++) {
        comp++;
        if(x[j]==i || x[j]-i==j-k || x[j]-i==k-j)
            return 0;
    }
    return 1;
}

void nQueens(int k) {
    for(int i=1;i<=n;i++) {
        if(place(k,i)) {
            x[k]=i;
            if(k==n) {
                solutions++;
                cout<<endl<<"Solution "<<solutions<<":";
                for(int j=1;j<=n;j++)
                    cout<<"\t"<<x[j];
                if(solutions==1)
                    for(int j=1;j<=n;j++)
                        first[j]=x[j];
            }
            else
                nQueens(k+1);
        }
    }
}

int main() {
    int i,j;
    cout<<"Enter the number of queens:";
    cin>>n;

    cout<<endl<<"Column of the queen in each row 1.."<<n<<":";
    clock_t start=clock();
    nQueens(1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(solutions>0) {
        cout<<endl<<endl<<"Board for solution 1:";
        for(i=1;i<=n;i++) {
            cout<<endl;
            for(j=1;j<=n;j++)
                if(first[i]==j)
                    cout<<"Q ";
                else
                    cout<<". ";
        }
    }
    cout<<endl<<"Total solutions:"<<solutions;
    cout<<endl<<"Number of comparisons:"<<comp;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n!)";
    cout<<endl;
}


// Output:
// Enter the number of queens:4
//
// Column of the queen in each row 1..4:
// Solution 1:	2	4	1	3
// Solution 2:	3	1	4	2
//
// Board for solution 1:
// . Q . .
// . . . Q
// Q . . .
// . . Q .
// Total solutions:2
// Number of comparisons:84
// Time taken:0.000003 seconds
// Time complexity: O(n!)
