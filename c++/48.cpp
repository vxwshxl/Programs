// 48. Write a constructor in c++ to input the length,height and breadth of 3 wooden piece and calculate and print the total size in CFT using destructor

#include <iostream>
using namespace std;

class woodframe {
    double l,b,h;
    double kb1,kb2,kb3,kb;

    public:
        woodframe();
        ~woodframe();
};

woodframe::woodframe() {
    int i;
    i=1;
    cout<<"3 Pieces of wooden Frame:";
    while(i<=3) {
        cout<<endl<<"Enter the Length[Foot]:";
        cin>>l;
        cout<<endl<<"Enter the Breadth[inch]:";
        cin>>b;
        cout<<endl<<"Enter the Height[inch]:";
        cin>>h;
        if(i==1) {
            kb1=(b/12*h/12*l);
        }
        else if(i==2) {
            kb2=(b/12*h/12*l);
        }
        else if(i==3) {
            kb3=(b/12*h/12*l);
        }
        i++;
    }
}

woodframe::~woodframe() {
    kb=kb1+kb2+kb3;
    cout<<endl<<"total size"<<kb<<"KB";
}

int main() {
    woodframe wf;
    return 0;
}


// Output:
3 Pieces of wooden Frame:
Enter the Length[Foot]:6

Enter the Breadth[inch]:3.5

Enter the Height[inch]:5

Enter the Length[Foot]:6

Enter the Breadth[inch]:3.5

Enter the Height[inch]:6

Enter the Length[Foot]:6

Enter the Breadth[inch]:5

Enter the Height[inch]:3.5

total size2.33333KB