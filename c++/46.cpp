// 46. Write the member functions in c++ to input the number of elements in an array and print the reverse sequence of that input elements  using virtual function or late binding.

#include <iostream>
using namespace std;

class array {
    public:
        virtual void display() {
            cout << "Virtual Function:" << endl;
        }
};

class reverse:public array {
    int a[10], i, n;
    public:
        void display() {
            cout<<endl<<"Enter the number of elements:";
            cin>>n;
            cout<<endl<<"Enter the elements:";
        
            for(i=0;i<n;i++)
                cin>>a[i];
            cout<<endl<<"Elements in input sequence:";
            
            for(i=0;i<n;i++) {
                cout<<"\t"<<a[i];
            }
            cout<<endl<<"Elements in Reverse sequence:";
            for(i=n-1;i>=0;i--) {
                cout<<"\t"<<a[i];
            }
        }
};

int main() {
    array* a;
    reverse b;     //object of derived class    
    a = &b;
    //b.display();   
    a->display();   //Late Binding occurs    
    return 0;
}

// Output:
Enter the number of elements:5

Enter the elements:4
5
6
7
8

Elements in input sequence:	4	5	6	7	8
Elements in Reverse sequence:	8	7	6	5	4  