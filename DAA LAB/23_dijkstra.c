// 23. Write a program in c to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm and find its execution time using the time function.

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

    int order[n+1],pos[n+1],trace[n+1][n+1];
    char cell[12];

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
        step++;
        order[step]=u;
        pos[u]=step;
        for(v=1;v<=n;v++)
            trace[step][v]=d[v];
        for(v=1;v<=n;v++)
            if(w[u][v]!=0)
                relax(u,v);
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nS = { }");
    printf("\nS = {%d}  (source, d[%d] = 0)\n",s,s);
    printf("\nu     ");
    for(v=1;v<=n;v++)
        if(v!=s)
            printf("%-6d",v);
    printf("S");
    for(i=2;i<=step;i++) {
        if(trace[i][order[i]]==INF)
            break;
        printf("\n%-6d",order[i]);
        for(v=1;v<=n;v++) {
            if(v==s)
                continue;
            if(trace[i][v]==INF)
                printf("%-6s","INF");
            else if(pos[v]<=i) {
                sprintf(cell,"(%d)",trace[i][v]);
                printf("%-6s",cell);
            }
            else
                printf("%-6d",trace[i][v]);
        }
        printf("{");
        for(j=1;j<=i;j++)
            printf(j==1?"%d":", %d",order[j]);
        printf("}");
    }
    printf("\n( ) = vertex is in S, its shortest distance is final");

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
    printf("\nTime complexity: O(V^2) with adjacency matrix, O(E log V) with adjacency list");
    printf("\nSpace complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list");
    printf("\n");
    return 0;
}


// Output 1:
// Enter the number of vertices:6
// Enter the 6x6 weight matrix (0 for no edge):
// 0 2 4 0 0 0
// 0 0 1 7 0 0
// 0 0 0 0 3 0
// 0 0 0 0 0 1
// 0 0 0 2 0 5
// 0 0 0 0 0 0
// Enter the source vertex:1
// S = { }
// S = {1}  (source, d[1] = 0)
//
// u     2     3     4     5     6     S
// 2     (2)   4     INF   INF   INF   {1, 2}
// 3     (2)   (3)   9     INF   INF   {1, 2, 3}
// 5     (2)   (3)   9     (6)   INF   {1, 2, 3, 5}
// 4     (2)   (3)   (8)   (6)   11    {1, 2, 3, 5, 4}
// 6     (2)   (3)   (8)   (6)   (9)   {1, 2, 3, 5, 4, 6}
// ( ) = vertex is in S, its shortest distance is final
//
// Vertex	Distance	Path
// 1	0		1
// 2	2		1 -> 2
// 3	3		1 -> 2 -> 3
// 4	8		1 -> 2 -> 3 -> 5 -> 4
// 5	6		1 -> 2 -> 3 -> 5
// 6	9		1 -> 2 -> 3 -> 5 -> 4 -> 6
// Number of comparisons:44
// Time taken:0.000002 seconds
// Time complexity: O(V^2) with adjacency matrix, O(E log V) with adjacency list
// Space complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list

// Output 2:
// Enter the number of vertices:6
// Enter the 6x6 weight matrix (0 for no edge):
// 0 50 45 10 0 0
// 0 0 10 15 0 0
// 0 0 0 0 30 0
// 20 0 0 0 15 0
// 0 20 35 0 0 0
// 0 0 0 0 3 0
// Enter the source vertex:1
// S = { }
// S = {1}  (source, d[1] = 0)
//
// u     2     3     4     5     6     S
// 4     50    45    (10)  INF   INF   {1, 4}
// 5     50    45    (10)  (25)  INF   {1, 4, 5}
// 2     (45)  45    (10)  (25)  INF   {1, 4, 5, 2}
// 3     (45)  (45)  (10)  (25)  INF   {1, 4, 5, 2, 3}
// ( ) = vertex is in S, its shortest distance is final
//
// Vertex	Distance	Path
// 1	0		1
// 2	45		1 -> 4 -> 5 -> 2
// 3	45		1 -> 3
// 4	10		1 -> 4
// 5	25		1 -> 4 -> 5
// 6	unreachable
// Number of comparisons:47
// Time taken:0.000002 seconds
// Time complexity: O(V^2) with adjacency matrix, O(E log V) with adjacency list
// Space complexity: O(V^2) with adjacency matrix, O(V+E) with adjacency list
