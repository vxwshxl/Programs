// 27. Write a program in c to find the minimum cost spanning tree of a graph using Kruskal's algorithm and find its execution time using the time function.

/*
Algorithm: MST-KRUSKAL(G, w)

1. A <- Ø
2. for each vertex v in V[G]
3.       do MAKE-SET(v)
4. sort the edges of E into nondecreasing order by weight w
5. for each edge (u,v) in E, taken in nondecreasing order by weight
6.       do if FIND-SET(u) != FIND-SET(v)
7.             then A <- A U {(u,v)}
8.                  UNION(u,v)
9. return A

MAKE-SET(x)
1. parent[x] <- x
2. rank[x] <- 0

FIND-SET(x)
1. if x != parent[x]
2.       then parent[x] <- FIND-SET(parent[x])
3. return parent[x]

UNION(x, y)
1. x <- FIND-SET(x), y <- FIND-SET(y)
2. if rank[x] > rank[y]
3.       then parent[y] <- x
4.       else parent[x] <- y
5.            if rank[x] == rank[y]
6.                  then rank[y] <- rank[y] + 1
*/

#include<stdio.h>
#include<time.h>

int parent[50],rnk[50];

void make_set(int x) {
    parent[x]=x;
    rnk[x]=0;
}

int find_set(int x) {
    if(x!=parent[x])
        parent[x]=find_set(parent[x]);
    return parent[x];
}

void union_set(int x,int y) {
    x=find_set(x);
    y=find_set(y);
    if(rnk[x]>rnk[y])
        parent[y]=x;
    else {
        parent[x]=y;
        if(rnk[x]==rnk[y])
            rnk[y]++;
    }
}

int main() {
    int n,e,i,j,k=0,cost=0,count=0,tu,tv,tw;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    int u[e],v[e],w[e],au[n],av[n],aw[n];
    printf("Enter the edges (vertex vertex weight):\n");
    for(i=0;i<e;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);

    clock_t start=clock();
    for(i=1;i<=n;i++)
        make_set(i);
    for(i=1;i<e;i++) {
        tu=u[i];
        tv=v[i];
        tw=w[i];
        j=i-1;
        while(j>=0) {
            count++;
            if(w[j]<=tw)
                break;
            u[j+1]=u[j];
            v[j+1]=v[j];
            w[j+1]=w[j];
            j--;
        }
        u[j+1]=tu;
        v[j+1]=tv;
        w[j+1]=tw;
    }
    for(i=0;i<e && k<n-1;i++) {
        count++;
        if(find_set(u[i])!=find_set(v[i])) {
            au[k]=u[i];
            av[k]=v[i];
            aw[k]=w[i];
            k++;
            union_set(u[i],v[i]);
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(k<n-1)
        printf("\nGraph is disconnected, no spanning tree exists");
    else {
        printf("\nEdges in the minimum spanning tree (in the order added):");
        printf("\nEdge\t\tWeight");
        for(i=0;i<k;i++) {
            printf("\n%d - %d\t\t%d",au[i],av[i],aw[i]);
            cost+=aw[i];
        }
        printf("\nMinimum cost of spanning tree:%d",cost);
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(E log E) with merge sort, O(E^2) with the insertion sort used here");
    printf("\nSpace complexity: O(V+E)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of vertices:9
// Enter the number of edges:14
// Enter the edges (vertex vertex weight):
// 1 2 4
// 1 8 8
// 2 3 8
// 2 8 11
// 3 4 7
// 3 6 4
// 3 9 2
// 4 5 9
// 4 6 14
// 5 6 10
// 6 7 2
// 7 8 1
// 7 9 6
// 8 9 7
//
// Edges in the minimum spanning tree (in the order added):
// Edge		Weight
// 7 - 8		1
// 3 - 9		2
// 6 - 7		2
// 1 - 2		4
// 3 - 6		4
// 3 - 4		7
// 1 - 8		8
// 4 - 5		9
// Minimum cost of spanning tree:37
// Number of comparisons:71
// Time taken:0.000010 seconds
// Time complexity: O(E log E) with merge sort, O(E^2) with the insertion sort used here
// Space complexity: O(V+E)
