#include <bits/stdc++.h>
using namespace std;

void binary_search(int ar[], int n, int x) // fucntion for binary search with three parametes as array,size of array,no to be searched
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (ar[m] == x)
        {
            cout << "Element is Present in the Array at index: " << m << "\n";
            return;
        }

        // If x greater, ignore left half
        if (ar[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    cout << "Element is not Present in the Array\n"; // if element is not present in the array
}

int main() // main method
{
    int arr[5] = {8, 16, 4, 78, 44};       // Creating an array of size 5
    int to_be_searched = 78;               // the number to be searched
    binary_search(arr, 5, to_be_searched); // function call for binary search

    int arr1[5] = {18, 6, 41, 8, 21};        // Creating an array of size 5
    int to_be_searched1 = 2;                 // the number to be searched
    binary_search(arr1, 5, to_be_searched1); // function call for binary search
}
