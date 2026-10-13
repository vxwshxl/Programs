// 19. Write a program in c++ to solve the travelling salesman problem using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int cost[15][15];
int g[1<<15][15],nxt[1<<15][15];

int main() {
    int n,i,j,k,S,full,count=0;
    cout<<"Enter the number of cities:";
    cin>>n;
    cout<<"Enter the "<<n<<"x"<<n<<" cost matrix:"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>cost[i][j];

    clock_t start=clock();
    // g[S][i] = cheapest path from city i through every city in set S, ending at city 1
    full=(1<<n)-1;
    for(i=0;i<n;i++)
        g[0][i]=cost[i][0];
    for(S=1;S<=full;S++) {
        if(S&1)
            continue;
        for(i=0;i<n;i++) {
            if(S&(1<<i))
                continue;
            g[S][i]=999999999;
            for(k=1;k<n;k++) {
                if(S&(1<<k)) {
                    count++;
                    int c=cost[i][k]+g[S^(1<<k)][k];
                    if(c<g[S][i]) {
                        g[S][i]=c;
                        nxt[S][i]=k;
                    }
                }
            }
        }
    }
    S=full^1;
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Minimum cost of tour:"<<g[S][0];
    cout<<endl<<"Optimal tour:1";
    i=0;
    while(S!=0) {
        k=nxt[S][i];
        cout<<" -> "<<k+1;
        S=S^(1<<k);
        i=k;
    }
    cout<<" -> 1";
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n^2 * 2^n)";
    cout<<endl;
}


// Output:
// Enter the number of cities:4
// Enter the 4x4 cost matrix:
// 0 10 15 20
// 5 0 9 10
// 6 13 0 12
// 8 8 9 0
//
// Minimum cost of tour:35
// Optimal tour:1 -> 2 -> 4 -> 3 -> 1
// Number of comparisons:24
// Time taken:0.000003 seconds
// Time complexity: O(n^2 * 2^n)
