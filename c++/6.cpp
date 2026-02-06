// 6. Write a function in c++ to print the sum of the following fractional series 1+1/2+1/3+1/4....1/n after input the nth values.

#include <iostream>
#include <cmath>
using namespace std;

double findsum(int N){
    double sum = 0;
    for(int i=1;i<=N;i++){
        sum += pow((double)1/i,i);
    }
    return sum;
}

int main(){
    int N;
    cout<<"Enter the value of N: ";
    cin>>N;
    double sum = findsum(N);
    cout<<"Sum of the Series is: "<<sum<<endl;
    
    return 0;
}