// 13. Write a program in c to solve the 0/1 knapsack problem using dynamic programming and find its execution time using the time function.

/*
Algorithm: Knapsack01(v, wt, n, W)

1. Start
2. For w <- 0 to W do
3.        V[0][w] <- 0
4. For i <- 1 to n do
5.        For w <- 0 to W do
6.              if wt[i] <= w and v[i] + V[i-1][w-wt[i]] > V[i-1][w] then
7.                    V[i][w] <- v[i] + V[i-1][w-wt[i]]
8.                    keep[i][w] <- 1
9.              else
10.                   V[i][w] <- V[i-1][w]
11.                   keep[i][w] <- 0
12. print "Maximum value" V[n][W]
13. w <- W
14. For i <- n down to 1 do
15.       if keep[i][w] == 1 then
16.             print "Item i selected"
17.             w <- w - wt[i]
18. Stop
*/

#include<stdio.h>
#include<time.h>

int main() {
    int n,W,i,w,count=0;
    printf("Enter the number of items:");
    scanf("%d",&n);
    int v[n+1],wt[n+1];
    printf("Enter the values of %d items:",n);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("Enter the weights of %d items:",n);
    for(i=1;i<=n;i++)
        scanf("%d",&wt[i]);
    printf("Enter the capacity of the knapsack:");
    scanf("%d",&W);
    int V[n+1][W+1],keep[n+1][W+1];

    clock_t start=clock();
    for(w=0;w<=W;w++)
        V[0][w]=0;
    for(i=1;i<=n;i++) {
        for(w=0;w<=W;w++) {
            count++;
            if(wt[i]<=w && v[i]+V[i-1][w-wt[i]]>V[i-1][w]) {
                V[i][w]=v[i]+V[i-1][w-wt[i]];
                keep[i][w]=1;
            }
            else {
                V[i][w]=V[i-1][w];
                keep[i][w]=0;
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nV[i,w] table:\ni\\w");
    for(w=0;w<=W;w++)
        printf("\t%d",w);
    for(i=0;i<=n;i++) {
        printf("\n%d",i);
        for(w=0;w<=W;w++)
            printf("\t%d",V[i][w]);
    }
    printf("\nMaximum value:%d",V[n][W]);
    printf("\nItems selected:");
    w=W;
    for(i=n;i>=1;i--) {
        if(keep[i][w]==1) {
            printf("\tItem %d(v=%d,w=%d)",i,v[i],wt[i]);
            w=w-wt[i];
        }
    }
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(nW)");
    printf("\nSpace complexity: O(nW)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of items:4
// Enter the values of 4 items:10 40 30 50
// Enter the weights of 4 items:5 4 6 3
// Enter the capacity of the knapsack:10
//
// V[i,w] table:
// i\w	0	1	2	3	4	5	6	7	8	9	10
// 0	0	0	0	0	0	0	0	0	0	0	0
// 1	0	0	0	0	0	10	10	10	10	10	10
// 2	0	0	0	0	40	40	40	40	40	50	50
// 3	0	0	0	0	40	40	40	40	40	50	70
// 4	0	0	0	50	50	50	50	90	90	90	90
// Maximum value:90
// Items selected:	Item 4(v=50,w=3)	Item 2(v=40,w=4)
// Number of comparisons:44
// Time taken:0.000001 seconds
// Time complexity: O(nW)
// Space complexity: O(nW)
