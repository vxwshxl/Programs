// 51. Write a constructor C++ to Convert Hours in Terms of Minutes and Seconds.

#include<iostream>
using namespace std;

class clock1 {
    float hrs, min, sec = 0;

    public:
        clock1() {
            cout << "Enter hours : ";
            cin >> hrs;
            min = hrs * 60;
            sec = min * 60;
            cout << endl << hrs << " hours = " << min << " minutes = " << sec << " seconds";
        }
};

int main() {
    clock1 ck1;
    return 0;
}


// Output:
Enter hours : 5

5 hours = 300 minutes = 18000 seconds