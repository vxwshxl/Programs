// Sir skipped this, its custom Program to fill gap of 12 no.

// 12. Write an OOP in c++ to print the Fibonacci series up to n terms.

#include <iostream>
using namespace std;

class fibonacci{
    int n, f0, f1, fib;
    public:
        void generate();
};

void fibonacci::generate(){
    f0 = 0;
    f1 = 1;
    cout<<endl<<"Enter the number of terms: ";
    cin>>n;
    
    cout<<endl<<"Fibonacci Series: ";
    for(int i=1; i<=n; i++){
        if(i == 1){
            cout<<f0<<" ";
            continue;
        }
        if(i == 2){
            cout<<f1<<" ";
            continue;
        }
        fib = f0 + f1;
        f0 = f1;
        f1 = fib;
        cout<<fib<<" ";
    }
}

int main(){
    fibonacci f;
    f.generate();
    return 0;
}


// Output:
Enter the number of terms: 7
Fibonacci Series: 0 1 1 2 3 5 8 