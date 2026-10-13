// 16. Write a program in c++ to construct an optimal prefix code using Huffman coding (greedy method) and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

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
    if(lft[z]==-1 && rgt[z]==-1) {
        cout<<endl<<ch[z]<<"\t"<<f[z]<<"\t";
        if(depth==0)
            cout<<"0";
        for(int i=0;i<depth;i++)
            cout<<code[i];
        return;
    }
    code[depth]=0;
    printCodes(lft[z],depth+1);
    code[depth]=1;
    printCodes(rgt[z],depth+1);
}

int main() {
    int n,i;
    cout<<"Enter the number of characters:";
    cin>>n;
    cout<<"Enter the "<<n<<" characters:";
    for(i=0;i<n;i++)
        cin>>ch[i];
    cout<<"Enter the frequencies of "<<n<<" characters:";
    for(i=0;i<n;i++) {
        cin>>f[i];
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

    cout<<endl<<"Huffman codes:"<<endl<<"Char\tFreq\tCode";
    printCodes(root,0);
    cout<<endl<<"Total frequency at root:"<<f[root];
    cout<<endl<<"Number of comparisons:"<<comp;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n log n)";
    cout<<endl;
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
// Time taken:0.000000 seconds
// Time complexity: O(n log n)
