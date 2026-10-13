// 21. Write a program in c++ to traverse a graph using depth first search (DFS) and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int adj[50][50],visited[50],d[50],f[50];
int n,t=0,comp=0;

void dfsVisit(int u) {
    visited[u]=1;
    d[u]=++t;
    cout<<"\t"<<u;
    for(int v=1;v<=n;v++) {
        comp++;
        if(adj[u][v]==1 && visited[v]==0)
            dfsVisit(v);
    }
    f[u]=++t;
}

int main() {
    int u,v,s;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter the "<<n<<"x"<<n<<" adjacency matrix:"<<endl;
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            cin>>adj[u][v];
    cout<<"Enter the source vertex:";
    cin>>s;

    clock_t start=clock();
    for(u=1;u<=n;u++)
        visited[u]=0;
    cout<<endl<<"DFS traversal:";
    dfsVisit(s);
    for(u=1;u<=n;u++)
        if(visited[u]==0)
            dfsVisit(u);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Vertex\tDiscovery\tFinish";
    for(u=1;u<=n;u++)
        cout<<endl<<u<<"\t"<<d[u]<<"\t\t"<<f[u];
    cout<<endl<<"Number of comparisons:"<<comp;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix";
    cout<<endl;
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
// Time taken:0.000002 seconds
// Time complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix
