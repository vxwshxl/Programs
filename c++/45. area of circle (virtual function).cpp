// 45. Write the member functions in c++ to input the value of the radius and print the area of the circle using virtual function or late binding.

#include <iostream>    
using namespace std;

class circle {
    public:
        virtual void display() {
            cout << "Virtual Function:" << endl;
        }
};

class Area:public circle {
    float r,a;
    public:
        void display() {
            cout<<"Enter the value of Radius:";
            cin>>r;
            a=3.14*r*r;  
            cout << "Area of the circle"<<a<<endl;    
        }    
};

int main() {
    circle* a;
    Area b;     // Object of derived class
    a = &b;
    a->display();   // Late Binding occurs
    return 0;
}

// Output:
Enter the value of Radius:4
Area of the circle50.24