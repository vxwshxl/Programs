//14. Write a constructor in c++ to input the elements in an array and  print the smallest and largest element from that array  using the concept of constructor overloading

#include<iostream>
#include<stdlib.h>
using namespace std;

class array {
  int a[10],n,m;
  public:
    array();
    array(int);
};

array::array() {
  int i;
  cout<<endl<<"Enter the Dimension:";
  cin>>n;
  cout<<endl<<"Enter the Elements:";

  for(i=0;i<n;i++)
    cin>>a[i];
  m=0;

  for(i=0;i<n;i++) {
    if(a[i]>=m) {
      m=a[i];
    }
  }
  cout<<endl<<"Largest Elements"<<m;
}

array::array(int i) {
  cout<<endl<<"Enter the Dimension:";
  cin>>n;
  cout<<endl<<"Enter the Elements:";
  for(i=0;i<n;i++)
    cin>>a[i];
  m=a[0];
  for(i=0;i<n;i++) {
    if(a[i]<=m) {
      m=a[i];
    }
  }
  cout<<endl<<"Smallest Elements"<<m;;
}

int main() {
  int a1;
  cout<<endl<<"Constructor Overloading:";
  cout<<endl<<"Largest Element from an array";
  array sw;
  cout<<endl<<"Smallest Element from an array";
  array se(a1);
}


// Output:
Constructor Overloading:
Largest Element from an array
Enter the Dimension:3

Enter the Elements:3
4
5

Largest Elements5
Smallest Element from an array
Enter the Dimension:6

Enter the Elements:4
5
6
7
8
9
Smallest Elements4