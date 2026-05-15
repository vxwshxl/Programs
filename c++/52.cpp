// 52. Write a member function in c++  to print the prime number from 1 to n using trial division approach.

#include <iostream>
using namespace std;

class prime {
    public:
        bool isPrime(int n) {
            // Since 1 is not prime return false
            if (n == 1 )
                return false;
            // Check divisiblity with all number in
            // range [2, n - 1]
            for (int i = 2; i < n; i++) {
                // If the n is divisible by i,
                if (n % i == 0)
                    return false;
            }
            // If no divisor is found
            return true;
        }
};

int main() {
    prime p;
    int n;
    cout<<endl<<"Enter the end term[prime number list]";
    cin>>n;
    // Check every number from 1 to n
    for (int i = 1; i <= n; i++) {

        // Check if current number is prime
        if (p.isPrime(i))
            cout << i << " ";
    }
    return 0;
}


// Output:
Enter the end term[prime number list]50
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47