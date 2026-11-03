// 22. Write a program in c to solve the job assignment problem using branch and bound and find its execution time using the time function.

/*
Algorithm: JOB-ASSIGNMENT(C, n)   (Least Cost Branch and Bound)
(lb(X) = cost of the jobs assigned so far in X
         + for every worker not yet assigned, his cheapest job among the jobs still free)

1. Start
2. Create the root node: no worker assigned, cost <- 0
3. lb(root) <- lower bound of root
4. Insert root into the list of live nodes
5. While the list of live nodes is not empty do
6.       E <- the live node with minimum lb
7.       Remove E from the list of live nodes
8.       if all n workers are assigned in E then
9.             print the assignment in E and its cost as the optimal solution
10.            Stop
11.      i <- the next worker to be assigned in E
12.      For each job j not yet assigned in E do
13.            Create a child X of E with worker i assigned job j
14.            cost(X) <- cost(E) + C[i][j]
15.            lb(X) <- lower bound of X
16.            Insert X into the list of live nodes
17. Stop
*/

#include<stdio.h>
#include<time.h>
#define INF 99999
#define MAX 100000

int n,c[15][15],count=0,total=0;
int parent[MAX],level[MAX],job[MAX],used[MAX],cost[MAX],lb[MAX],live[MAX];

int bound(int k) {
    int i,j,min,b=cost[k];
    for(i=level[k]+1;i<=n;i++) {
        min=INF;
        for(j=1;j<=n;j++) {
            count++;
            if(!(used[k]&(1<<j)) && c[i][j]<min)
                min=c[i][j];
        }
        b+=min;
    }
    return b;
}

void new_node(int p,int j) {
    int k=total++;
    parent[k]=p;
    if(p==-1) {
        level[k]=0;
        job[k]=0;
        used[k]=0;
        cost[k]=0;
    }
    else {
        level[k]=level[p]+1;
        job[k]=j;
        used[k]=used[p]|(1<<j);
        cost[k]=cost[p]+c[level[k]][j];
    }
    lb[k]=bound(k);
    live[k]=1;
}

void assignment(int k) {
    if(parent[k]==-1) {
        printf("root");
        return;
    }
    if(parent[parent[k]]!=-1) {
        assignment(parent[k]);
        printf(", ");
    }
    printf("W%d->J%d",level[k],job[k]);
}

int main() {
    int i,j,k,E,ans=-1,expanded=0;
    printf("Enter the number of workers/jobs:");
    scanf("%d",&n);
    printf("Enter the %dx%d cost matrix (row = worker, column = job):\n",n,n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);

    int order[MAX],first[MAX];

    clock_t start=clock();
    new_node(-1,0);
    while(1) {
        E=-1;
        for(k=0;k<total;k++) {
            if(live[k]) {
                count++;
                if(E==-1 || lb[k]<lb[E])
                    E=k;
            }
        }
        if(E==-1)
            break;
        live[E]=0;
        if(level[E]==n) {
            ans=E;
            break;
        }
        order[expanded]=E;
        first[expanded]=total;
        expanded++;
        for(j=1;j<=n;j++)
            if(!(used[E]&(1<<j)))
                new_node(E,j);
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nNodes expanded (least lb first):");
    for(i=0;i<expanded;i++) {
        E=order[i];
        printf("\nE = {");
        assignment(E);
        printf("}  lb = %d",lb[E]);
        for(k=first[i];k<first[i]+n-level[E];k++)
            printf("\n      W%d->J%d   cost = %-4d lb = %d",level[k],job[k],cost[k],lb[k]);
    }

    printf("\n\nOptimal assignment:");
    for(i=1;i<=n;i++) {
        k=ans;
        while(level[k]!=i)
            k=parent[k];
        printf("\nWorker %d -> Job %d\tcost = %d",i,job[k],c[i][job[k]]);
    }
    printf("\nMinimum total cost:%d",cost[ans]);
    printf("\nNodes generated:%d",total);
    printf("\nNodes expanded:%d",expanded);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n!) in the worst case, far less when the bound prunes the tree");
    printf("\nSpace complexity: O(n!) in the worst case for the live nodes");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of workers/jobs:4
// Enter the 4x4 cost matrix (row = worker, column = job):
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
//
// Nodes expanded (least lb first):
// E = {root}  lb = 10
//       W1->J1   cost = 9    lb = 17
//       W1->J2   cost = 2    lb = 10
//       W1->J3   cost = 7    lb = 20
//       W1->J4   cost = 8    lb = 18
// E = {W1->J2}  lb = 10
//       W2->J1   cost = 8    lb = 13
//       W2->J3   cost = 5    lb = 14
//       W2->J4   cost = 9    lb = 17
// E = {W1->J2, W2->J1}  lb = 13
//       W3->J3   cost = 9    lb = 13
//       W3->J4   cost = 16   lb = 25
// E = {W1->J2, W2->J1, W3->J3}  lb = 13
//       W4->J4   cost = 13   lb = 13
//
// Optimal assignment:
// Worker 1 -> Job 2	cost = 2
// Worker 2 -> Job 1	cost = 6
// Worker 3 -> Job 3	cost = 1
// Worker 4 -> Job 4	cost = 4
// Minimum total cost:13
// Nodes generated:11
// Nodes expanded:4
// Number of comparisons:121
// Time taken:0.000009 seconds
// Time complexity: O(n!) in the worst case, far less when the bound prunes the tree
// Space complexity: O(n!) in the worst case for the live nodes
