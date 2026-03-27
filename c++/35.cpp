35. write a program  in c++ to print the sum of nth terms using static data members with static member functions.
#include <iostream>
using namespace std;
class Box
{ private:
	static int sum;
	public:
	static void print()
	{
int i,n;
cout<<endl<<"Enter the Terms:";
cin>>n;
for(i=1;i<=n;i++)
{
sum=sum+i;
}
          cout << "The value of the length is: " << sum << endl;
	
	}
};

// initialize the static data members

int Box :: sum = 0;
main()
{       Box b;
	cout << "Static member function is called through Object name: " << endl;
	b.print();
	cout << "\nStatic member function is called through Class name:[2 times of sum of terms] " << endl;
	Box::print();
	
}
output:
Static member function is called through Object name:

Enter the Terms:6
The value of the length is: 21

Static member function is called through Class name:[2 times of sum of terms]

Enter the Terms:4
The value of the length is: 31
36. write a member function in c++ to concatenate the two input strings
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
output:
Enter string s1: rahul
Enter string s2: das

Resultant String = rahuldas

37.write a constructor in c++ to compare the two input string and compare it using strcmp() where output of the both input string is highlighted in bold letter.
#include <cstring>
#include <iostream>
#define b "\e[1m"
#define cb "\e[0m"
using namespace std;
class stringcom
{char str1[30];// = "Megadeth";
  char str2[30];// = "Metallica";
  public:
stringcom();
};
stringcom::stringcom()
{
cout<<"Enter a string:";
  cin.getline(str1,30);
  cout<<"Enter another string:";
  cin.getline(str2,30);
   int result;
  result = strcmp(str1, str2);

  cout << "Comparing " <<b<< str1 <<cb<< " and " << b<<str2<<cb << ": " <<result << endl;
}
 main() {
stringcom s1;  
 }

output:
Enter a string:pranab
Enter another string:arnab
Comparing pranab and arnab: 15
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
