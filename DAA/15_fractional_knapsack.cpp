// 17. Write a program in c++ to solve the fractional knapsack problem using the greedy method and find its execution time using the time function.

#include<iostream>
#include<time.h>
using namespace std;

double r[50];

void merge(int a[],int low,int mid,int high,int &count) {
    int n1=mid-low+1,n2=high-mid;
    int left[n1],right[n2];
    int i,j,k;

    for(i=0;i<n1;i++)
        left[i]=a[low+i];
    for(j=0;j<n2;j++)
        right[j]=a[mid+1+j];

    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2) {
        count++;
        if(r[left[i]]>=r[right[j]])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
    while(i<n1)
        a[k++]=left[i++];
    while(j<n2)
        a[k++]=right[j++];
}

void mergeSort(int a[],int low,int high,int &count) {
    if(low<high) {
        int mid=(low+high)/2;
        mergeSort(a,low,mid,count);
        mergeSort(a,mid+1,high,count);
        merge(a,low,mid,high,count);
    }
}

int main() {
    int n,i,k,count=0;
    double W;
    cout<<"Enter the number of items:";
    cin>>n;
    double v[n+1],w[n+1],x[n+1];
    int order[n];
    cout<<"Enter the values of "<<n<<" items:";
    for(i=1;i<=n;i++)
        cin>>v[i];
    cout<<"Enter the weights of "<<n<<" items:";
    for(i=1;i<=n;i++)
        cin>>w[i];
    cout<<"Enter the capacity of the knapsack:";
    cin>>W;

    clock_t start=clock();
    for(i=1;i<=n;i++) {
        r[i]=v[i]/w[i];
        x[i]=0;
        order[i-1]=i;
    }
    mergeSort(order,0,n-1,count);
    double remaining=W,total=0;
    for(k=0;k<n && remaining>0;k++) {
        i=order[k];
        count++;
        if(w[i]<=remaining) {
            x[i]=1;
            remaining=remaining-w[i];
        }
        else {
            x[i]=remaining/w[i];
            remaining=0;
        }
        total=total+x[i]*v[i];
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<endl<<"Items in decreasing order of value/weight:"<<endl<<"Item\tValue\tWeight\tv/w\tFraction";
    for(k=0;k<n;k++) {
        i=order[k];
        cout<<endl<<i<<"\t"<<v[i]<<"\t"<<w[i]<<"\t"<<r[i]<<"\t"<<x[i];
    }
    cout<<endl<<"Maximum value:"<<total;
    cout<<endl<<"Number of comparisons:"<<count;
    cout<<endl<<"Time taken:"<<fixed<<time_taken<<" seconds";
    cout<<endl<<"Time complexity: O(n log n)";
    cout<<endl;
}


// Output:
// Enter the number of items:4
// Enter the values of 4 items:10 40 30 50
// Enter the weights of 4 items:5 4 6 3
// Enter the capacity of the knapsack:10
//
// Items in decreasing order of value/weight:
// Item	Value	Weight	v/w	Fraction
// 4	50	3	16.6667	1
// 2	40	4	10	1
// 3	30	6	5	0.5
// 1	10	5	2	0
// Maximum value:105
// Number of comparisons:8
// Time taken:0.000005 seconds
// Time complexity: O(n log n)
