// 11. Write a member function in c++ to sort the elements using bubble sorting with function overriding.

#include<iostream>
using namespace std;

class bubble {
    public:
        void sort();
};

void bubble::sort() {
    cout<<endl<<"Bubble Sorting:";
}

class sorting:public bubble {
    int i,j,n,temp;
    public:
        void sort();
};

void sorting::sort() {
    cout<<endl<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<endl<<"Enter the elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(j=0;j<n;j++) {
        cout<<"\t"<<a[j];
    }
}

int main() {
    sorting s1=sorting();
    s1.sort();
}


// Output:
Enter the number of elements:5
Enter the elements:7
5
9
3
2
After Bubble Sorting:	2	3	5	7	9