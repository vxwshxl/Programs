// 44. Write the template class to input the radius of the circle and side of the Rhombous and print the perimeter of circle and Rhombous using template class overloading.

#include <iostream>  
using namespace std;  

template<class X> void fun(X r) {
    double pi,p;
    pi=3.14;
    cout<<endl<<"Enter the Radius value";
    cin>>r;
    p=2*pi*r;
    cout << "Perimeter of Circle : " <<p<< endl;  
}  

template<class X,class Y> void fun(X s ,Y c) {   
    cout<<endl<<"Enter the side value of Rhombous:";
    cin>>s;
    c=4*s;
    cout << "Perimeter of Rhombous : " <<c<< endl;  
}  

int main() {  
    int r1,s1,c1;
    fun(r1);  
    fun(s1,c1);
    return 0;
}  

// Output:
Enter the Radius value4
Perimeter of Circle : 25.12

Enter the side value of Rhombous:5
Perimeter of Rhombous : 20