56.write a member function in c++ to check whether a given matrix is magic matrix or not
#include <bits/stdc++.h>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
using namespace std;
class matrix1
{
public:
// Returns true if mat[][] is magic
// square, else returns false.
bool isMagicSquare(int mat[][3])
{
	int n = my_sizeof(mat)/my_sizeof(mat[0]);
	// calculate the sum of
	// the prime diagonal
	int i=0,j=0;
	// sumd1 and sumd2 are the sum of the two diagonals
	int sumd1 = 0, sumd2=0;
	for (i = 0; i < n; i++)
	{
		// (i, i) is the diagonal from top-left -> bottom-right
		// (i, n - i - 1) is the diagonal from top-right -> bottom-left
		sumd1 += mat[i][i];
		sumd2 += mat[i][n-1-i];
	}
	// if the two diagonal sums are unequal then it is not a magic square
	if(sumd1!=sumd2)
		return false;

	// For sums of Rows
	for (i = 0; i < n; i++) {
		
		int rowSum = 0, colSum = 0;
		for (j = 0; j < n; j++)
		{
			rowSum += mat[i][j];
			colSum += mat[j][i];
		}
		if (rowSum != colSum || colSum != sumd1)
			return false;
	}
return true;
}
};
// driver program to
// test above function
int main()
{
matrix1 m1;
	int mat[3][3] ;
	
	int i,j,m,n;
	cout<<endl<<"Enter the number of Rows:";
	cin>>m;
	cout<<endl<<"Enter the number of Cols:";
	cin>>n;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	cin>>mat[i][j];
	if (m1.isMagicSquare(mat))
		cout << "It is a Magic Square Matrix";
	else
		cout << "It is Not a magic Square Matrix";
	
	return 0;
}
//example of magic matrix(sum of rows and column and diagonal are same)
/*2 7 6
 9 5 1
 4 3 8*/
/*
1 2 2
2 2 1
2 1 2
*/
output:
Enter the number of Rows:3

Enter the number of Cols:3
1
2
2
2
2
1
2
1
2
It is a Magic Square Matrix