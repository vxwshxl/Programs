// 14. Write a program in c to find the longest common subsequence (LCS) of two sequences using dynamic programming and find its execution time using the time function.

/*
Algorithm: LCS-Length(X, Y, m, n)

1. Start
2. For i <- 1 to m do
3.        c[i][0] <- 0
4. For j <- 0 to n do
5.        c[0][j] <- 0
6. For i <- 1 to m do
7.        For j <- 1 to n do
8.              if X[i] == Y[j] then
9.                    c[i][j] <- c[i-1][j-1] + 1
10.                   b[i][j] <- 'D'
11.             else if c[i-1][j] >= c[i][j-1] then
12.                   c[i][j] <- c[i-1][j]
13.                   b[i][j] <- 'U'
14.             else
15.                   c[i][j] <- c[i][j-1]
16.                   b[i][j] <- 'L'
17. print "Length of LCS" c[m][n]
18. PrintLCS(b, X, m, n)
19. Stop

Algorithm: PrintLCS(b, X, i, j)

1. If (i == 0 or j == 0) then
2.        Return
3. If b[i][j] == 'D' then
4.        PrintLCS(b, X, i-1, j-1)
5.        print X[i]
6. else if b[i][j] == 'U' then
7.        PrintLCS(b, X, i-1, j)
8. else
9.        PrintLCS(b, X, i, j-1)
*/

#include<stdio.h>
#include<string.h>
#include<time.h>

int c[50][50];
char b[50][50];
char x[50],y[50];

void printLCS(int i,int j) {
    if(i==0 || j==0)
        return;
    if(b[i][j]=='D') {
        printLCS(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='U')
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}

int main() {
    int m,n,i,j,count=0;
    printf("Enter the first sequence X:");
    scanf("%s",x);
    printf("Enter the second sequence Y:");
    scanf("%s",y);
    m=strlen(x);
    n=strlen(y);

    clock_t start=clock();
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            count++;
            if(x[i-1]==y[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1]) {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nc[i,j] table (D=diagonal, U=up, L=left):\n\t\t");
    for(j=0;j<n;j++)
        printf("%c\t",y[j]);
    for(i=0;i<=m;i++) {
        printf("\n");
        if(i==0)
            printf("\t");
        else
            printf("%c\t",x[i-1]);
        for(j=0;j<=n;j++)
            if(i==0 || j==0)
                printf("%d\t",c[i][j]);
            else
                printf("%d%c\t",c[i][j],b[i][j]);
    }
    printf("\nLength of LCS:%d",c[m][n]);
    printf("\nLCS:");
    printLCS(m,n);
    printf("\nNumber of comparisons:%d",count);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(mn)");
    printf("\nSpace complexity: O(mn)");
    printf("\n");
    return 0;
}


// Output:
// Enter the first sequence X:ABCBDAB
// Enter the second sequence Y:BDCABA
//
// c[i,j] table (D=diagonal, U=up, L=left):
// 		B	D	C	A	B	A
// 	0	0	0	0	0	0	0
// A	0	0U	0U	0U	1D	1L	1D
// B	0	1D	1L	1L	1U	2D	2L
// C	0	1U	1U	2D	2L	2U	2U
// B	0	1D	1U	2U	2U	3D	3L
// D	0	1U	2D	2U	2U	3U	3U
// A	0	1U	2U	2U	3D	3U	4D
// B	0	1D	2U	2U	3U	4D	4U
// Length of LCS:4
// LCS:BCBA
// Number of comparisons:42
// Time taken:0.000002 seconds
// Time complexity: O(mn)
// Space complexity: O(mn)
