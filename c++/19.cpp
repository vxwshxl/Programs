// 19. Write the constructors in c++ to input the value of the radius and calculate and print the diameter,area and perimeter of the circle using the concept of multiple inheritance.

#include<iostream>
using namespace std;

class circlearea {
    protected:
        double pi, ar;
        int r;
    public:
        circlearea();
};

class diameter {
    protected:
        int d;
        double r1;
    public:
        diameter();
};

class circleperi:public circlearea, public diameter {
    float pr;
    public:
        circleperi();
};

circlearea::circlearea() {
    pi=3.14;
    cout<<endl<<"Area:";
    cout<<endl<<"enter the value of Radius:";
    cin>>r;
    ar=2*pi*r;
    cout<<endl<<"Area of the circle="<<ar;
}

circleperi::circleperi() {
    pi=3.14;
    cout<<endl<<"Perimeter:";
    cout<<endl<<"enter the value of Radius:";
    cin>>r;
    pr=pi*r*r;
    cout<<endl<<"Perimeter of the circle="<<pr;
}

diameter::diameter() {
    cout<<endl<<"Diameter:";
    cout<<endl<<"enter the value of Radius:";
    cin>>r1;
    d=2*r1;
    cout<<endl<<"Diameter of the circle="<<d;
}

int main() {
    circleperi ci;
}


// Output:
Area:
enter the value of Radius:5

Area of the circle=31.4
Diameter:
enter the value of Radius:4

Diameter of the circle=8
Perimeter:
enter the value of Radius:7

Perimeter of the circle=153.86