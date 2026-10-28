// 24. Write a program in c to find the shortest path from a source vertex to all other vertices using the Bellman-Ford algorithm and find its execution time using the time function.

/*
Algorithm: BELLMAN-FORD(G, w, s)

1. Start
2. For each vertex v in G do
3.        d[v] <- infinity
4.        p[v] <- NIL
5. d[s] <- 0
6. For i <- 1 to n-1 do
7.        For each edge (u,v) in G do
8.              if d[u] + w(u,v) < d[v] then
9.                    d[v] <- d[u] + w(u,v)
10.                   p[v] <- u
11. For each edge (u,v) in G do
12.       if d[u] + w(u,v) < d[v] then
13.             print "Graph contains a negative weight cycle"
14.             Stop
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
    int n,e,i,j,s,neg=0,count=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    int u[e],v[e],w[e],d[n+1];
    printf("Enter the edges (source destination weight):\n");
    for(j=0;j<e;j++)
        scanf("%d%d%d",&u[j],&v[j],&w[j]);
    printf("Enter the source vertex:");
    scanf("%d",&s);

    clock_t start=clock();
    for(i=1;i<=n;i++) {
        d[i]=INF;
        p[i]=0;
    }
    d[s]=0;
    for(i=1;i<=n-1;i++)
        for(j=0;j<e;j++) {
            count++;
            if(d[u[j]]!=INF && d[u[j]]+w[j]<d[v[j]]) {
                d[v[j]]=d[u[j]]+w[j];
                p[v[j]]=u[j];
            }
        }
    for(j=0;j<e;j++) {
        count++;
        if(d[u[j]]!=INF && d[u[j]]+w[j]<d[v[j]]) {
            neg=1;
            break;
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(neg)
        printf("\nGraph contains a negative weight cycle");
    else {
        printf("\nVertex\tDistance\tPath");
        for(i=1;i<=n;i++) {
            if(d[i]==INF)
                printf("\n%d\tunreachable",i);
            else {
                printf("\n%d\t%d\t\t",i,d[i]);
                path(i);
            }
        }
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(VE)");
    printf("\nSpace complexity: O(V+E)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:5
// Enter the number of edges:10
// Enter the edges (source destination weight):
// 1 2 6
// 1 4 7
// 2 3 5
// 2 4 8
// 2 5 -4
// 3 2 -2
// 4 3 -3
// 4 5 9
// 5 1 2
// 5 3 7
// Enter the source vertex:1
//
// Vertex	Distance	Path
// 1	0		1
// 2	2		1 -> 4 -> 3 -> 2
// 3	4		1 -> 4 -> 3
// 4	7		1 -> 4
// 5	-2		1 -> 4 -> 3 -> 2 -> 5
// Number of comparisons:50
// Time taken:0.000009 seconds
// Time complexity: O(VE)
// Space complexity: O(V+E)
