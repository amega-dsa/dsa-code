#include <iostream>
using namespace std;

// the code below shows how to declare multi dimensional array
int main()
{
 int two_D_arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // or {{1,2,3,4},{5,6,7,8},{9,10,11,12}}

 // For a 3 dimensional array
 int three_D_arr[2][3][4] = {3, 4, 2, 3, 0, -3, 9, 11, 23, 12, 23, 2, 13, 4, 56, 3, 5, 9, 3, 5, 5, 1, 4, 9};
 // or {{{3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}},{{13, 4, 56, 3}, {5, 9, 3, 5}, { 5, 1, 4, 9 } }}

 // Traversing a 2-dimensional array using nested loop
 for (int i = 0; i < 3; ++i) // access rows of the array
 {
  // access columns of the array
  for (int j = 0; j < 4; ++j)
  {
   cout << "two_d_arr[" << i << "][" << j << "] = " << two_D_arr[i][j] << endl;
  }
 }
}