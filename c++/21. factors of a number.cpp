// 21. Write a programming in c++ to display the factors of the given number.
 
#include<iostream>
using namespace std;

int main() {
    int n, temp = 1;
    cout << "Enter the number[to print its factors:] " << endl;
    cin >> n;
    cout << "The factors of " << n << " are : " << endl;
    while (temp <= n) {
        if (!(n % temp)) {
            cout << temp << " ";
        }
        temp++;
    }
    cout << endl;
}


// Output:
Enter the number[to print its factors:]
15
The factors of 15 are :
1 3 5 15