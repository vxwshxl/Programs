// 18. Write a program in c to solve the N-Queen problem using backtracking and find its execution time using the time function.

/*
Algorithm: Place(k, i)
(returns true if a queen can be placed in row k, column i)

1. For j <- 1 to (k-1) do
2.        if x[j] == i or |x[j] - i| == |j - k| then
3.              Return false
4. Return true

Algorithm: NQueens(k, n)

1. Start
2. For i <- 1 to n do
3.        if Place(k, i) then
4.              x[k] <- i
5.              if k == n then
6.                    print x[1..n]
7.              else
8.                    NQueens(k+1, n)
9. Stop
*/

#include<stdio.h>
#include<time.h>

int x[20],first[20];
int n,solutions=0,comp=0;

int place(int k,int i) {
    int j;
    for(j=1;j<k;j++) {
        comp++;
        if(x[j]==i || x[j]-i==j-k || x[j]-i==k-j)
            return 0;
    }
    return 1;
}

void nQueens(int k) {
    int i,j;
    for(i=1;i<=n;i++) {
        if(place(k,i)) {
            x[k]=i;
            if(k==n) {
                solutions++;
                printf("\nSolution %d:",solutions);
                for(j=1;j<=n;j++)
                    printf("\t%d",x[j]);
                if(solutions==1)
                    for(j=1;j<=n;j++)
                        first[j]=x[j];
            }
            else
                nQueens(k+1);
        }
    }
}

int main() {
    int i,j;
    printf("Enter the number of queens:");
    scanf("%d",&n);

    printf("\nColumn of the queen in each row 1..%d:",n);
    clock_t start=clock();
    nQueens(1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    if(solutions>0) {
        printf("\n\nBoard for solution 1:");
        for(i=1;i<=n;i++) {
            printf("\n");
            for(j=1;j<=n;j++)
                if(first[i]==j)
                    printf("Q ");
                else
                    printf(". ");
        }
    }
    printf("\nTotal solutions:%d",solutions);
    printf("\nNumber of comparisons:%d",comp);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n!)");
    printf("\nSpace complexity: O(n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of queens:4
//
// Column of the queen in each row 1..4:
// Solution 1:	2	4	1	3
// Solution 2:	3	1	4	2
//
// Board for solution 1:
// . Q . .
// . . . Q
// Q . . .
// . . Q .
// Total solutions:2
// Number of comparisons:84
// Time taken:0.000008 seconds
// Time complexity: O(n!)
// Space complexity: O(n)
