// 26. Write a program in c to find the minimum cost spanning tree of a graph using Prim's algorithm and find its execution time using the time function.

/*
Algorithm: MST-PRIM(G, w, r)

1. for each u in V[G]
2.       do key[u] <- infinity
3.          p[u] <- NIL
4. key[r] <- 0
5. Q <- V[G]
6. while Q != Ø
7.       do u <- EXTRACT-MIN(Q)
8.          for each v in Adj[u]
9.                do if v in Q and w(u,v) < key[v]
10.                     then p[v] <- u
11.                          key[v] <- w(u,v)

EXTRACT-MIN(Q)
1. u <- the vertex in Q with minimum key[u]
2. Q <- Q - {u}
3. return u
*/

#include<stdio.h>
#include<time.h>
#define INF 99999

int n,count=0;
int w[50][50],key[50],p[50],Q[50];

int extract_min() {
    int v,u=0;
    for(v=1;v<=n;v++) {
        count++;
        if(Q[v]==1 && (u==0 || key[v]<key[u]))
            u=v;
    }
    Q[u]=0;
    return u;
}

int main() {
    int i,u,v,r,q_size,step=0,cost=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the %dx%d weight matrix (0 for no edge):\n",n,n);
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            scanf("%d",&w[u][v]);
    printf("Enter the root vertex:");
    scanf("%d",&r);

    int order[n+1];

    clock_t start=clock();
    for(u=1;u<=n;u++) {
        key[u]=INF;
        p[u]=0;
    }
    key[r]=0;
    for(u=1;u<=n;u++)
        Q[u]=1;
    q_size=n;
    while(q_size!=0) {
        u=extract_min();
        q_size--;
        if(key[u]==INF)
            break;
        step++;
        order[step]=u;
        for(v=1;v<=n;v++)
            if(w[u][v]!=0) {
                count++;
                if(Q[v]==1 && w[u][v]<key[v]) {
                    p[v]=u;
                    key[v]=w[u][v];
                }
            }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(step<n)
        printf("\nGraph is disconnected, no spanning tree exists");
    else {
        printf("\nEdges in the minimum spanning tree (in the order added):");
        printf("\nEdge\t\tWeight");
        for(i=2;i<=n;i++) {
            v=order[i];
            printf("\n%d - %d\t\t%d",p[v],v,key[v]);
            cost+=key[v];
        }
        printf("\nMinimum cost of spanning tree:%d",cost);
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(V^2) with adjacency matrix, O(E log V) with adjacency list and binary heap");
    printf("\nSpace complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:9
// Enter the 9x9 weight matrix (0 for no edge):
// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0
// Enter the root vertex:1
//
// Edges in the minimum spanning tree (in the order added):
// Edge		Weight
// 1 - 2		4
// 2 - 3		8
// 3 - 9		2
// 3 - 6		4
// 6 - 7		2
// 7 - 8		1
// 3 - 4		7
// 4 - 5		9
// Minimum cost of spanning tree:37
// Number of comparisons:109
// Time taken:0.000005 seconds
// Time complexity: O(V^2) with adjacency matrix, O(E log V) with adjacency list and binary heap
// Space complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list
