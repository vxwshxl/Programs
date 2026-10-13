// 20. Write a program in c++ to traverse a graph using breadth first search (BFS) and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,i,u,v,s,front=0,rear=0,count=0;
    cout<<"Enter the number of vertices:";
    cin>>n;
    int adj[n+1][n+1],visited[n+1],d[n+1],Q[n];
    cout<<"Enter the "<<n<<"x"<<n<<" adjacency matrix:"<<endl;
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            cin>>adj[u][v];
    cout<<"Enter the source vertex:";
    cin>>s;

    clock_t start=clock();
    for(u=1;u<=n;u++) {
        visited[u]=0;
        d[u]=-1;
    }
    visited[s]=1;
    d[s]=0;
    Q[rear++]=s;
    cout<<endl<<"BFS traversal:";
    while(front<rear) {
        u=Q[front++];
        cout<<"\t"<<u;
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

    cout<<endl<<"Vertex\tDistance from "<<s;
    for(i=1;i<=n;i++)
        if(d[i]==-1)
            cout<<endl<<i<<"\tunreachable";
        else
            cout<<endl<<i<<"\t"<<d[i];
    cout<<endl<<"Number of comparisons:"<<count;
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
//
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
// Time taken:0.000002 seconds
// Time complexity: O(V+E) with adjacency list, O(V^2) with adjacency matrix
