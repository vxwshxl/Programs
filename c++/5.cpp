// 5. Write a member function in c++ to implement the uses of this pointer.

#include <iostream>
using namespace std;

class Test{
    private:
        int x;
    public:
        void setX(int x){
            this->x = x;
        }
        void print(){
            cout<<"x = "<<x<<endl;
        }
};

int main(){
    Test obj;
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    obj.setX(x);
    obj.print();

    return 0;
}