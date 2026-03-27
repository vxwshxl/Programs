// 36. write a member function in c++ to concatenate the two input strings
#include<iostream>
using namespace std;
class string1
{
string s1,s2,result;
public:
void concate();
};
void string1::concate()
{
    cout<< "Enter string s1: ";
    getline(cin, s1);
    cout<<"Enter string s2: ";
    getline(cin, s2);
    result = s1 + s2;
    cout<<endl<<"Resultant String = "<< result;
}
 main()
{
string1 s1;    
s1.concate();
}
/*output:
Enter string s1: rahul
Enter string s2: das

Resultant String = rahuldas*/