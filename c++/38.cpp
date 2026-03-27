38.write a program in c++ to input a string in lowercase character and convert it to uppercase character
#include <iostream>
#include <cstring>
using namespace std;
main()
{
   char ch[40]; int i,p;
   cout<<"Enter a character in lowercase: ";
   cin.getline(ch,40);
p=strlen(ch);
for(i=0;i<=p;i++)
{
if(ch[i]>=97 && ch[i]<=122)
{
ch[i]=ch[i]-32;
}
}
   cout<<"Entered character in uppercase: "<<ch;

}
output:
Enter a character in lowercase: rahul das
Input Character in uppercase: RAHUL DAS