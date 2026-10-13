// 19. Write a program in c to solve the travelling salesman problem using dynamic programming and find its execution time using the time function.

/*
Algorithm: TSP(cost, n)
(g(i, S) = cheapest path that starts at city i, visits every city in set S once, and ends at city 1)

1. Start
2. For i <- 2 to n do
3.        g(i, {}) <- cost[i][1]
4. For each set S not containing city 1, in increasing size do
5.        For each city i not in S do
6.              g(i, S) <- infinity
7.              For each city k in S do
8.                    if cost[i][k] + g(k, S - {k}) < g(i, S) then
9.                          g(i, S) <- cost[i][k] + g(k, S - {k})
10.                         next(i, S) <- k
11. print "Minimum cost" g(1, {2, 3, ..., n})
12. Follow next(i, S) from city 1 to print the tour
13. Stop
*/

#include<stdio.h>
#include<time.h>

int cost[15][15];
int g[1<<15][15],nxt[1<<15][15];

int main() {
    int n,i,j,k,S,full,count=0;
    printf("Enter the number of cities:");
    scanf("%d",&n);
    printf("Enter the %dx%d cost matrix:\n",n,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    clock_t start=clock();
    // S is a bitmask of cities; bit 0 (city 1) is never in S
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

    printf("\nMinimum cost of tour:%d",g[S][0]);
    printf("\nOptimal tour:1");
    i=0;
    while(S!=0) {
        k=nxt[S][i];
        printf(" -> %d",k+1);
        S=S^(1<<k);
        i=k;
    }
    printf(" -> 1");
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n^2 * 2^n)");
    printf("\n");
    return 0;
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
// Time taken:0.000008 seconds
// Time complexity: O(n^2 * 2^n)
