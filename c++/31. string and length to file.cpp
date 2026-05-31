// 31. Write a file programming in c++ to input a string and print the string and length of that string in a file.

#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;
int main() {
    char str1[40];
    cout<<endl<<"Enter a String:";
    fstream new_file;

    cin.getline(str1,40);
    int l=strlen(str1);
    new_file.open("new_file.txt",ios::out);  

    for(int i=0;i<l;i++)
        new_file.put(str1[i]);
    new_file<<endl<<"lengh of the string="<<l;
    new_file.close();
}


// Output:
Enter a String:rahul
$ cat new_file.txt
rahul
lengh of the string=5