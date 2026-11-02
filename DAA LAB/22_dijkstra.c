// 22. Write a program in c to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm and find its execution time using the time function.

/*
Algorithm: DA(G, w, s)

1. INITIALIZE-SINGLE-SOURCE(G, s)
2. S <- Ø
3. Q <- V[G]
4. while Q != Ø
5.       do u <- EXTRACT-MIN(Q)
6.          S <- S U {u}
7.          for each vertex v in Adj[u]
8.                do RELAX(u, v, w)

INITIALIZE-SINGLE-SOURCE(G, s)
1. for each vertex v in V[G]
2.       do d[v] <- infinity
3.          p[v] <- NIL
4. d[s] <- 0

EXTRACT-MIN(Q)
1. u <- the vertex in Q with minimum d[u]
2. Q <- Q - {u}
3. return u

RELAX(u, v, w)
1. if d[v] > d[u] + w(u,v)
2.       then d[v] <- d[u] + w(u,v)
3.            p[v] <- u
*/

#include<stdio.h>
#include<time.h>
#define INF 99999

int n,count=0;
int w[50][50],d[50],p[50],S[50],Q[50];

void initialize_single_source(int s) {
    int v;
    for(v=1;v<=n;v++) {
        d[v]=INF;
        p[v]=0;
    }
    d[s]=0;
}

int extract_min() {
    int v,u=0;
    for(v=1;v<=n;v++) {
        count++;
        if(Q[v]==1 && (u==0 || d[v]<d[u]))
            u=v;
    }
    Q[u]=0;
    return u;
}

void relax(int u,int v) {
    count++;
    if(d[v]>d[u]+w[u][v]) {
        d[v]=d[u]+w[u][v];
        p[v]=u;
    }
}

void path(int v) {
    if(p[v]==0) {
        printf("%d",v);
        return;
    }
    path(p[v]);
    printf(" -> %d",v);
}

int main() {
    int i,j,u,v,s,q_size,step=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the %dx%d weight matrix (0 for no edge):\n",n,n);
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            scanf("%d",&w[u][v]);
    printf("Enter the source vertex:");
    scanf("%d",&s);

    int order[n+1],trace[n+1][n+1];

    clock_t start=clock();
    initialize_single_source(s);
    for(v=1;v<=n;v++)
        S[v]=0;
    for(v=1;v<=n;v++)
        Q[v]=1;
    q_size=n;
    while(q_size!=0) {
        u=extract_min();
        q_size--;
        S[u]=1;
        for(v=1;v<=n;v++)
            if(w[u][v]!=0)
                relax(u,v);
        step++;
        order[step]=u;
        for(v=1;v<=n;v++)
            trace[step][v]=d[v];
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nStep  u    ");
    for(v=1;v<=n;v++)
        printf("d[%d]  ",v);
    printf("S");
    for(i=1;i<=step;i++) {
        printf("\n%-6d%-5d",i,order[i]);
        for(v=1;v<=n;v++) {
            if(trace[i][v]==INF)
                printf("%-6s","INF");
            else
                printf("%-6d",trace[i][v]);
        }
        printf("{");
        for(j=1;j<=i;j++)
            printf(j==1?"%d":", %d",order[j]);
        printf("}");
    }

    printf("\n\nVertex\tDistance\tPath");
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
// Step  u    d[1]  d[2]  d[3]  d[4]  d[5]  S
// 1     1    0     10    INF   5     INF   {1}
// 2     4    0     8     14    5     7     {1, 4}
// 3     5    0     8     13    5     7     {1, 4, 5}
// 4     2    0     8     9     5     7     {1, 4, 5, 2}
// 5     3    0     8     9     5     7     {1, 4, 5, 2, 3}
//
// Vertex	Distance	Path
// 1	0		1
// 2	8		1 -> 4 -> 2
// 3	9		1 -> 4 -> 2 -> 3
// 4	5		1 -> 4
// 5	7		1 -> 4 -> 5
// Number of comparisons:35
// Time taken:0.000003 seconds
// Time complexity: O(V^2) with adjacency matrix, O((V+E) log V) with binary heap
// Space complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list
