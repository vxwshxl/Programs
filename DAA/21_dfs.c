// 21. Write a program in c to traverse a graph using depth first search (DFS) and find its execution time using the time function.

/*
Algorithm: DFS(G, s)

1. Start
2. For each vertex u in G do
3.        visited[u] <- 0
4. time <- 0
5. DFS-Visit(s)
6. For each vertex u in G do
7.        if visited[u] == 0 then
8.              DFS-Visit(u)
9. Stop

Algorithm: DFS-Visit(u)

1. visited[u] <- 1
2. time <- time+1, d[u] <- time
3. print u
4. For each vertex v adjacent to u do
5.        if visited[v] == 0 then
6.              DFS-Visit(v)
7. time <- time+1, f[u] <- time
*/

#include<stdio.h>
#include<time.h>

int adj[50][50],visited[50],d[50],f[50];
int n,t=0,count=0;

void dfsVisit(int u) {
    int v;
    visited[u]=1;
    d[u]=++t;
    printf("\t%d",u);
    for(v=1;v<=n;v++) {
        count++;
        if(adj[u][v]==1 && visited[v]==0)
            dfsVisit(v);
    }
    f[u]=++t;
}

int main() {
    int u,v,s;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the %dx%d adjacency matrix:\n",n,n);
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            scanf("%d",&adj[u][v]);
    printf("Enter the source vertex:");
    scanf("%d",&s);

    clock_t start=clock();
    for(u=1;u<=n;u++)
        visited[u]=0;
    printf("\nDFS traversal:");
    dfsVisit(s);
    for(u=1;u<=n;u++)
        if(visited[u]==0)
            dfsVisit(u);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nVertex\tDiscovery\tFinish");
    for(u=1;u<=n;u++)
        printf("\n%d\t%d\t\t%d",u,d[u],f[u]);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:6
// Enter the 6x6 adjacency matrix:
// 0 1 1 0 0 0
// 1 0 0 1 1 0
// 1 0 0 0 1 0
// 0 1 0 0 0 1
// 0 1 1 0 0 1
// 0 0 0 1 1 0
// Enter the source vertex:1
//
// DFS traversal:	1	2	4	6	5	3
// Vertex	Discovery	Finish
// 1	1		12
// 2	2		11
// 3	6		7
// 4	3		10
// 5	5		8
// 6	4		9
// Number of comparisons:36
// Time taken:0.000006 seconds
// Time complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix
