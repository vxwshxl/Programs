// 37. Write a constructor in c++ to compare the two input string and compare it using strcmp() where output of the both input string is highlighted in bold letter.

#include <cstring>
#include <iostream>
#define b "\e[1m"
#define cb "\e[0m"
using namespace std;

class stringcom {
    char str1[30];// = "Megadeth";
    char str2[30];// = "Metallica";
    public:
        stringcom();
};

stringcom::stringcom() {
    cout<<"Enter a string:";
    cin.getline(str1,30);
    cout<<"Enter another string:";
    cin.getline(str2,30);
    int result;
    result = strcmp(str1, str2);

    cout << "Comparing " <<b<< str1 <<cb<< " and " << b<<str2<<cb << ": " <<result << endl;
}

int main() {
    stringcom s1;  
}


// Output:
Enter a string:pranab
Enter another string:arnab
Comparing pranab and arnab: 15