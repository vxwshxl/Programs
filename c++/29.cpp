// 29. Write the constructor in c++ to search the input element using linear searching and if found print it in student.doc file.

#include<iostream>
#include<fstream>

using namespace std;
class linears {
    int i,n,item,a[10];
    public:
        linears();
};

linears::linears() {
    cout<<endl<<"Enter the number of elements:";
    cin>>n;
    cout<<endl<<"Enter the Elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<endl<<"Enter the Item to search:";
    cin>>item;
    ofstream fit("student3.doc");
    for(i=0;i<n;i++) {
        if(a[i]==item) {
            fit<<endl<<item<<"is found at"<<i<<"th position:";
            cout<<endl<<item<<"is found at"<<i<<"th position:";
            fit.close();
        }
    }
}

int main() {
    linears l1;
}

// Output:
Enter the number of elements:4

Enter the Elements:1
2
4
5

Enter the Item to search:4

4is found at2th position:
$ cat student3.doc
2is found at4th position: