49. write a file program in c++ to input the year and check whether it is a leap year or not.
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int year;
    ofstream file;

    cout << "Enter a year: ";
    cin >> year;

    // Open file in write mode
    file.open("leap.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        file << year << " is a leap year." << endl;
        cout << year << " is a leap year." << endl;
    } else {
        file << year << " is not a leap year." << endl;
        cout << year << " is not a leap year." << endl;
    }

    // Close the file
    file.close();

    return 0;
}    

output:
Enter a year: 1900
1900 is not a leap year.
cat leap.txt
1900 is not a leap year.