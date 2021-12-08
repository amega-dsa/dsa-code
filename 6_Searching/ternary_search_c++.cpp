#include <bits/stdc++.h>
using namespace std;

void ternary_search(int ar[], int n, int x) // fucntion for ternary search with three parametes as array,size of array,no to be searched
{
    int l = 0;
    int r = n - 1;
    while (r >= l)
    {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at mid1
        if (ar[mid1] ==x)
        {
            cout << "Element is Present in the Array at index: " << mid1 << "\n";
            return;
        }
        // Check if key is present at mid2
        if (ar[mid2] == x)
        {
            cout << "Element is Present in the Array at index: " << mid2 << "\n";
            return;
        }
        // Since key is not present at mid,check in which region it is present then repeat the Search operation in that region
        if (x < ar[mid1])
        {

            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (x > ar[mid2])
        {

            // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else
        {

            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    cout << "Element is not Present in the Array\n"; // if element is not present in the array
}

int main() // main method
{
    int arr[5] = {8, 16, 4, 78, 44};       // Creating an array of size 5
    int to_be_searched = 78;               // the number to be searched
    ternary_search(arr, 5, to_be_searched); // function call for ternary search

    int arr1[5] = {18, 6, 41, 8, 21};        // Creating an array of size 5
    int to_be_searched1 = 2;                 // the number to be searched
    ternary_search(arr1, 5, to_be_searched1); // function call for ternary search
}
