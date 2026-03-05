// 4. Write an OOP in c++ to print the sum of the following fractional series 1+1/2+1/3+1/4....1/n after the input nth values.

#include <iostream>
using namespace std;

class sumfraction{
    private:
        int n;
    public:
        void generate();
};

void sumfraction::generate(){
    double i, sum = 0.0;
    cout<<endl<<"Enter the limit: ";
    cin>>n;
    
    for(i=1;i<=n;i++){
        sum = sum+1/i;
    }
    
    cout<<endl<<"Sum of the Series: "<<sum;
}

int main() {
    sumfraction sf;
    sf.generate();
}


// Output:
Enter the limit: 5
Sum of the Series: 2.28333
