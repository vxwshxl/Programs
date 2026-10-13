// 17. Write a program in c to construct an optimal prefix code using Huffman coding (greedy method) and find its execution time using the time function.

/*
Algorithm: Huffman(C, f, n)

1. Start
2. Q <- min-priority queue of all n characters, keyed on frequency f
3. For i <- 1 to (n-1) do
4.        allocate a new node z
5.        x <- ExtractMin(Q)
6.        y <- ExtractMin(Q)
7.        left[z] <- x
8.        right[z] <- y
9.        f[z] <- f[x] + f[y]
10.       Insert(Q, z)
11. root <- ExtractMin(Q)
12. PrintCodes(root, "")
13. Stop

Algorithm: PrintCodes(z, code)

1. If z is a leaf then
2.        print character of z and code
3.        Return
4. PrintCodes(left[z], code + "0")
5. PrintCodes(right[z], code + "1")
*/

#include<stdio.h>
#include<time.h>

char ch[100];
int f[100],lft[100],rgt[100];
int Q[100],qsize=0,comp=0;
int code[100];

void heapify(int i) {
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<qsize) {
        comp++;
        if(f[Q[l]]<f[Q[smallest]])
            smallest=l;
    }
    if(r<qsize) {
        comp++;
        if(f[Q[r]]<f[Q[smallest]])
            smallest=r;
    }
    if(smallest!=i) {
        int t=Q[i];
        Q[i]=Q[smallest];
        Q[smallest]=t;
        heapify(smallest);
    }
}

int extractMin() {
    int min=Q[0];
    Q[0]=Q[qsize-1];
    qsize--;
    heapify(0);
    return min;
}

void insert(int z) {
    int i=qsize;
    Q[qsize++]=z;
    while(i>0) {
        int p=(i-1)/2;
        comp++;
        if(f[Q[i]]>=f[Q[p]])
            break;
        int t=Q[i];
        Q[i]=Q[p];
        Q[p]=t;
        i=p;
    }
}

void printCodes(int z,int depth) {
    int i;
    if(lft[z]==-1 && rgt[z]==-1) {
        printf("\n%c\t%d\t",ch[z],f[z]);
        if(depth==0)
            printf("0");
        for(i=0;i<depth;i++)
            printf("%d",code[i]);
        return;
    }
    code[depth]=0;
    printCodes(lft[z],depth+1);
    code[depth]=1;
    printCodes(rgt[z],depth+1);
}

int main() {
    int n,i;
    printf("Enter the number of characters:");
    scanf("%d",&n);
    printf("Enter the %d characters:",n);
    for(i=0;i<n;i++)
        scanf(" %c",&ch[i]);
    printf("Enter the frequencies of %d characters:",n);
    for(i=0;i<n;i++) {
        scanf("%d",&f[i]);
        lft[i]=rgt[i]=-1;
    }

    clock_t start=clock();
    for(i=0;i<n;i++)
        insert(i);
    int next=n;
    for(i=1;i<=n-1;i++) {
        int z=next++;
        int x=extractMin();
        int y=extractMin();
        lft[z]=x;
        rgt[z]=y;
        f[z]=f[x]+f[y];
        insert(z);
    }
    int root=extractMin();
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nHuffman codes:\nChar\tFreq\tCode");
    printCodes(root,0);
    printf("\nTotal frequency at root:%d",f[root]);
    printf("\nNumber of comparisons:%d",comp);
    printf("\nTime taken:%f seconds",time_taken);
    printf("\nTime complexity: O(n log n)");
    printf("\n");
    return 0;
}


// Output:
// Enter the number of characters:6
// Enter the 6 characters:a b c d e f
// Enter the frequencies of 6 characters:45 13 12 16 9 5
//
// Huffman codes:
// Char	Freq	Code
// a	45	0
// c	12	100
// b	13	101
// f	5	1100
// e	9	1101
// d	16	111
// Total frequency at root:100
// Number of comparisons:27
// Time taken:0.000005 seconds
// Time complexity: O(n log n)
