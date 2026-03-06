// 25. Write the functions in c++ to calculate cft and price from a wooden piece using menu using function overloading.

#include<iostream>
#include<stdlib.h>
using namespace std;

void wood(double,double,double);
void wood(double,double);
void wood(double l,double b,double h) {
    double cft;
    cout<<endl<<"Enter the Length:";
    cin>>l;
    cout<<endl<<"Enter the Breadth:";
    cin>>b;
    cout<<endl<<"Enter the Height:";
    cin>>h;
    cft=b/12*l/12*h;
    cout<<"Total size="<<cft<<"KB";
}

void wood(double l,double h) {
    double b,kb,pr,p;
    cout<<endl<<"Enter the Length:";
    cin>>l;
    cout<<endl<<"Enter the Breadth:";
    cin>>b;
    cout<<endl<<"Enter the Height:";
    cin>>h;
    cout<<endl<<"Enter the Price per KB:";
    cin>>pr;
    kb=b/12*h/12*l;
    p=pr*kb;
    cout<<"Total Price:"<<p;
}

int main() {
    int ch;
    double pl,li,l2;
    while(1) {
        cout<<endl<<"Wooden Frame Details:";
        cout<<endl<<"1.Size in CFT[from a piece]:";
        cout<<endl<<"2.Price per CFT[from a piece]:";
        cout<<endl<<"3.EXIT:";
        cout<<endl<<"Enter your choice:";
        cin>>ch;
        switch(ch) {
            case 1:
                wood(pl,li,l2); break;
            case 2:wood(pl,li); break;
            case 3:exit(0);
            default:cout<<endl<<"Wrong choice:";
        }
    }
}


// Output:
Wooden Frame Details:
1.Size in CFT[from a piece]:
2.Price per CFT[from a piece]:
3.EXIT:
Enter your choice:1


Enter the Length:2


Enter the Breadth:4


Enter the Height:6
Total size=0.333333KB
Wooden Frame Details:
1.Size in CFT[from a piece]:
2.Price per CFT[from a piece]:
3.EXIT: