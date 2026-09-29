// 13. Write a program in c++ to solve the 0/1 knapsack problem using dynamic programming and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n,W,i,w,count=0;
    cout<<"Enter the number of items:";
    cin>>n;
    int v[n+1],wt[n+1];
    cout<<"Enter the values of "<<n<<" items:";
    for(i=1;i<=n;i++)
        cin>>v[i];
    cout<<"Enter the weights of "<<n<<" items:";
    for(i=1;i<=n;i++)
        cin>>wt[i];
    cout<<"Enter the capacity of the knapsack:";
    cin>>W;
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

    cout<<endl<<"V[i,w] table:"<<endl<<"i\\w";
    for(w=0;w<=W;w++)
        cout<<"\t"<<w;
    for(i=0;i<=n;i++) {
        cout<<endl<<i;
        for(w=0;w<=W;w++)
            cout<<"\t"<<V[i][w];
    }
    cout<<endl<<"Maximum value:"<<V[n][W];
    cout<<endl<<"Items selected:";
    w=W;
    for(i=n;i>=1;i--) {
        if(keep[i][w]==1) {
            cout<<"\tItem "<<i<<"(v="<<v[i]<<",w="<<wt[i]<<")";
            w=w-wt[i];
        }
    }
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(nW)";
    cout<<endl;
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
// Time taken:0.000011 seconds
// Time complexity: O(nW)
