53.write a program in c++ to input a term and print the pascal triangle of that term.
#include<iostream>
using namespace std;
int main()
{ int rows;
  cout << "Enter the number of rows : ";
  cin >> rows;
  cout << endl;
  for (int i = 0; i < rows; i++)
{
int val = 1;
for (int j = 1; j < (rows - i); j++)
{cout << "   ";
}
for (int k = 0; k <= i; k++)
{
cout << "      " << val;
val = val * (i - k) / (k + 1);
}cout << endl << endl;
 }
cout << endl;
return 0;
}
output:
Enter the number of rows : 9

                              1

                           1      1

                        1      2      1

                     1      3      3      1

                  1      4      6      4      1

               1      5      10      10      5      1

            1      6      15      20      15      6      1

         1      7      21      35      35      21      7      1

      1      8      28      56      70      56      28      8      1