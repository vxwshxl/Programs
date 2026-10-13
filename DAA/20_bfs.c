// 20. Write a program in c to traverse a graph using breadth first search (BFS) and find its execution time using the time function.

/*
Algorithm: BFS(G, s)

1. Start
2. For each vertex u in G do
3.        visited[u] <- 0
4.        d[u] <- infinity
5. visited[s] <- 1, d[s] <- 0
6. Enqueue(Q, s)
7. While Q is not empty do
8.        u <- Dequeue(Q)
9.        print u
10.       For each vertex v adjacent to u do
11.             if visited[v] == 0 then
12.                   visited[v] <- 1
13.                   d[v] <- d[u] + 1
14.                   Enqueue(Q, v)
15. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,i,u,v,s,front=0,rear=0,count=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int adj[n+1][n+1],visited[n+1],d[n+1],Q[n];
    printf("Enter the %dx%d adjacency matrix:\n",n,n);
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            scanf("%d",&adj[u][v]);
    printf("Enter the source vertex:");
    scanf("%d",&s);

    clock_t start=clock();
    for(u=1;u<=n;u++) {
        visited[u]=0;
        d[u]=-1;
    }
    visited[s]=1;
    d[s]=0;
    Q[rear++]=s;
    printf("\nBFS traversal:");
    while(front<rear) {
        u=Q[front++];
        printf("\t%d",u);
        for(v=1;v<=n;v++) {
            count++;
            if(adj[u][v]==1 && visited[v]==0) {
                visited[v]=1;
                d[v]=d[u]+1;
                Q[rear++]=v;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nVertex\tDistance from %d",s);
    for(i=1;i<=n;i++)
        if(d[i]==-1)
            printf("\n%d\tunreachable",i);
        else
            printf("\n%d\t%d",i,d[i]);
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
// BFS traversal:	1	2	3	4	5	6
// Vertex	Distance from 1
// 1	0
// 2	1
// 3	1
// 4	2
// 5	2
// 6	3
// Number of comparisons:36
// Time taken:0.000003 seconds
// Time complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix
