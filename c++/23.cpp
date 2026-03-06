// 23. write a programs in c++ to input the two terms and print the gcd of that term using the friend functions of two different classes

    #include <iostream>  
    using namespace std;  
    class second;          // forward declarartion.  
    class first  
    {  
        int x;  
        public:  
        void inputdata(int i)  
        {  
            x=i;  
        }  
        friend void gcd(first,second);         // friend function.  
    };  
    class second  
    {  
        int y;  
        public:  
        void inputdata(int i)  
        {  
            y=i;  
        }  
        friend void gcd(first,second);                    // friend function  
    };  
    void gcd(first n1,second n2)  
    {  
int gcd=1;
       for(int i = 1; i <= n1.x || i <= n2.y; i++)
{
 if(n1.x % i == 0 && n2.y % i == 0)
{
gcd=i;
}
}
cout <<"Greatest Common Divisior"<<gcd<<endl;
    }  
        main()  
    {  
       first a;  
       second b;
 int a1,b1;
 cout<<endl<<"Enter a number:";
 cin>>a1;
 cout<<endl<<"Enter another number:";
 cin>>b1;

       a.inputdata(a1);  
       b.inputdata(b1);  
       gcd(a,b);    
     }  
// output:
// Enter a number:5

// Enter another number:15
// Greatest Common Divisior5