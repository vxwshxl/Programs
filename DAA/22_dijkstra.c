// 22. Write a program in c to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm and find its execution time using the time function.

/*
Algorithm: DIJKSTRA(G, w, s)

1. Start
2. For each vertex u in G do
3.        d[u] <- infinity
4.        p[u] <- NIL
5.        visited[u] <- 0
6. d[s] <- 0
7. Repeat n times
8.        u <- unvisited vertex with minimum d[u]
9.        if d[u] == infinity then break
10.       visited[u] <- 1
11.       For each vertex v adjacent to u do
12.             if visited[v] == 0 and d[u] + w(u,v) < d[v] then
13.                   d[v] <- d[u] + w(u,v)
14.                   p[v] <- u
15. Print d[v] and the path to every vertex v using p
16. Stop
*/

#include<stdio.h>
#include<time.h>
#define INF 99999

int p[50];

void path(int v) {
    if(p[v]==0) {
        printf("%d",v);
        return;
    }
    path(p[v]);
    printf(" -> %d",v);
}

int main() {
    int n,i,j,u,v,s,min,count=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int w[n+1][n+1],d[n+1],visited[n+1];
    printf("Enter the %dx%d weight matrix (0 for no edge):\n",n,n);
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            scanf("%d",&w[u][v]);
    printf("Enter the source vertex:");
    scanf("%d",&s);

    clock_t start=clock();
    for(u=1;u<=n;u++) {
        d[u]=INF;
        p[u]=0;
        visited[u]=0;
    }
    d[s]=0;
    for(i=1;i<=n;i++) {
        u=0;
        min=INF;
        for(j=1;j<=n;j++) {
            count++;
            if(visited[j]==0 && d[j]<min) {
                min=d[j];
                u=j;
            }
        }
        if(u==0)
            break;
        visited[u]=1;
        for(v=1;v<=n;v++) {
            count++;
            if(w[u][v]!=0 && visited[v]==0 && d[u]+w[u][v]<d[v]) {
                d[v]=d[u]+w[u][v];
                p[v]=u;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nVertex\tDistance\tPath");
    for(i=1;i<=n;i++) {
        if(d[i]==INF)
            printf("\n%d\tunreachable",i);
        else {
            printf("\n%d\t%d\t\t",i,d[i]);
            path(i);
        }
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(V^2) with adjacency matrix, O((V+E) log V) with binary heap");
    printf("\nSpace complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:5
// Enter the 5x5 weight matrix (0 for no edge):
// 0 10 0 5 0
// 0 0 1 2 0
// 0 0 0 0 4
// 0 3 9 0 2
// 7 0 6 0 0
// Enter the source vertex:1
//
// Vertex	Distance	Path
// 1	0		1
// 2	8		1 -> 4 -> 2
// 3	9		1 -> 4 -> 2 -> 3
// 4	5		1 -> 4
// 5	7		1 -> 4 -> 5
// Number of comparisons:50
// Time taken:0.000007 seconds
// Time complexity: O(V^2) with adjacency matrix, O((V+E) log V) with binary heap
// Space complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list
