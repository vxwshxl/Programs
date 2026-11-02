// 23. Write a program in c to find the shortest paths between all pairs of vertices using the Floyd-Warshall algorithm and find its execution time using the time function.

/*
Algorithm: FLOYD-WARSHALL(W)

1. Start
2. n <- number of vertices
3. For i <- 1 to n do
4.        For j <- 1 to n do
5.              if i == j then D[i][j] <- 0
6.              else if there is an edge (i,j) then D[i][j] <- W[i][j]
7.              else D[i][j] <- infinity
8. For k <- 1 to n do
9.        For i <- 1 to n do
10.             For j <- 1 to n do
11.                   if D[i][k] + D[k][j] < D[i][j] then
12.                         D[i][j] <- D[i][k] + D[k][j]
13. Print D
14. Stop
*/

#include<stdio.h>
#include<time.h>
#define INF 99999

int main() {
    int n,i,j,k,count=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int D[n+1][n+1];
    printf("Enter the %dx%d weight matrix (0 for no edge):\n",n,n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&D[i][j]);

    clock_t start=clock();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j && D[i][j]==0)
                D[i][j]=INF;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) {
                count++;
                if(D[i][k]!=INF && D[k][j]!=INF && D[i][k]+D[k][j]<D[i][j])
                    D[i][j]=D[i][k]+D[k][j];
            }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nShortest distance matrix:\n");
    for(j=1;j<=n;j++)
        printf("\t%d",j);
    for(i=1;i<=n;i++) {
        printf("\n%d",i);
        for(j=1;j<=n;j++)
            if(D[i][j]==INF)
                printf("\tINF");
            else
                printf("\t%d",D[i][j]);
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(V^3)");
    printf("\nSpace complexity: O(V^2)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:4
// Enter the 4x4 weight matrix (0 for no edge):
// 0 3 0 7
// 8 0 2 0
// 5 0 0 1
// 2 0 0 0
//
// Shortest distance matrix:
// 	1	2	3	4
// 1	0	3	5	6
// 2	5	0	2	3
// 3	3	6	0	1
// 4	2	5	7	0
// Number of comparisons:64
// Time taken:0.000006 seconds
// Time complexity: O(V^3)
// Space complexity: O(V^2)
