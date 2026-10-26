// 12. Write a program in c to find the minimum number of scalar multiplications needed for matrix chain multiplication using dynamic programming and find its execution time using the time function.

/*
Algorithm: MatrixChainOrder(p, n)

1. Start
2. For i <- 1 to n do
3.        m[i][i] <- 0
4. For l <- 2 to n do
5.        For i <- 1 to (n-l+1) do
6.              j <- i+l-1
7.              m[i][j] <- infinity
8.              For k <- i to (j-1) do
9.                    q <- m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
10.                   if q < m[i][j] then
11.                         m[i][j] <- q
12.                         s[i][j] <- k
13. Print m[1][n] and PrintOrder(s, 1, n)
14. Stop

Algorithm: PrintOrder(s, i, j)

1. If (i == j) then
2.        print "A"i
3. else
4.        print "("
5.        PrintOrder(s, i, s[i][j])
6.        PrintOrder(s, s[i][j]+1, j)
7.        print ")"
*/

#include<stdio.h>
#include<time.h>

int s[20][20];

void printOrder(int i,int j) {
    if(i==j) {
        printf("A%d",i);
        return;
    }
    printf("(");
    printOrder(i,s[i][j]);
    printOrder(s[i][j]+1,j);
    printf(")");
}

int main() {
    int n,i,j,k,l,count=0;
    printf("Enter the number of matrices:");
    scanf("%d",&n);
    int p[n+1];
    printf("Enter the %d dimensions (matrix i is p[i-1] x p[i]):",n+1);
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);
    int m[20][20];

    clock_t start=clock();
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++) {
        for(i=1;i<=n-l+1;i++) {
            j=i+l-1;
            m[i][j]=999999999;
            for(k=i;k<j;k++) {
                count++;
                int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<m[i][j]) {
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nCost table:");
    for(i=1;i<=n;i++) {
        printf("\n");
        for(j=1;j<=n;j++)
            if(j<i)
                printf("\t-");
            else
                printf("\t%d",m[i][j]);
    }
    printf("\nMinimum number of multiplications:%d",m[1][n]);
    printf("\nOptimal parenthesization:");
    printOrder(1,n);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n^3)");
    printf("\nSpace complexity: O(n^2)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of matrices:4
// Enter the 5 dimensions (matrix i is p[i-1] x p[i]):5 4 6 2 7
//
// Cost table:
// 	0	120	88	158
// 	-	0	48	104
// 	-	-	0	84
// 	-	-	-	0
// Minimum number of multiplications:158
// Optimal parenthesization:((A1(A2A3))A4)
// Number of comparisons:10
// Time taken:0.000004 seconds
// Time complexity: O(n^3)
// Space complexity: O(n^2)
