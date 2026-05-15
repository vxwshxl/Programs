54.write a member function in c++ to input a number and check whether it is a krishnamurthy number or not.
//eg:1,2,145(1!+4!+5!=145),40585(4!+0!+5!+8!+5!=40585)(sum of factorial  is same of the given number)
#include<iostream>
using namespace std;   
class Kmr {
public:   
      int fact(int m)   
    {   int f = 1;   
        while (m != 0)
        {   
            f = f * m;   
            m=m-1;   }   
        return f;      }   
  void checkNumber(int n)   
    {   
        int sum = 0;    //initialize sum to 0   
          
        int temp = n;       
          while (temp != 0) {   
             sum = sum + fact(temp % 10);   
             temp = temp / 10;   
        }   
  if(sum == n)  
              cout<<endl<<n<<" is a krishnamurthy number";   
        else    
            cout<<endl<<n << "is not a krishnamurthy number";      
    }   
    };
  main()   
  {   
          Kmr k;
          int n1;    
         cout<<"Enter any number:";  
          cin>>n1;
         k.checkNumber(n1);   
               }   
output:
Enter any number:145

145 is a krishnamurthy number

Enter any number:6789

6789is not a krishnamurthy number