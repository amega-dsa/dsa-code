#include <bits/stdc++.h>
using namespace std;

void linear_search(int ar[], int n, int x) // fucntion for linear search with three parametes as array,size of array,no to be searched
{
    int found = 0; // flag variable
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == x) // checking if element is equal to the no to be searched
        {
            found = 1; // updating the flag
            index = i; // storing the index of the element found
            break;     // since the element is found therefore no need to traverse further thus exiting the loop
        }
    }

    if (found == 1) // if  element is present in the array then flag status is 1
    {
        cout << "Element is Present in the Array at index: "<<index<<"\n";
    }
    else
    {
        cout << "Element is not Present in the Array\n";
    }
}

int main() // main method
{
    int arr[5] = {8, 16, 4, 78, 2};        // Creating an array of size 5
    int to_be_searched = 2;                // the number to be searched
    linear_search(arr, 5, to_be_searched); // function call for linear search

    int arr1[5] = {18, 6, 41, 8, 21};        // Creating an array of size 5
    int to_be_searched1 = 2;                 // the number to be searched
    linear_search(arr1, 5, to_be_searched1); // function call for linear search
}