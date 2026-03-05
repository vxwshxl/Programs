// 10. Write C++ function to convert binary number  into decimal equivalent term.

#include <iostream>
using namespace std;

int binaryToDecimal(int n){
    int num = n;
	int dv = 0;
	int base = 1;
	int ld;
	int temp = num;
	while(temp!=0) {
		ld = temp % 10;//l=0,0,0,1
		temp = temp / 10;//100,10,1,0
		dv=dv + ld * base;//0+0*1=0,0+0*2=0,0*0+4=0,0+1*8=8
		base = base * 2;//1*2=2,2*2=4,4*2=8,8*2=16
	}
    
    return dv;
}

int main() {
	int num;
	cout<<endl<<"Enter a Binary number:";
	cin>>num;
	cout << binaryToDecimal(num) << endl;
}


// Output:
Enter a Binary number:1010
10