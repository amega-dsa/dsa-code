//INSERTION SORT C0DE

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i, j, temp;           //Initialising variables
    cin >> N;
    int arr[N];

    for (i = 0; i < N; i++)
    {
        cin >> arr[i];          //Taking input
    }

    for (i = 1; i < N; i++)
    {
        temp = arr[i];                       //  maintaing the ith element so as to get sorted arrray
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];                //replacong values
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Sorted array using Insertion sort is:" << endl;

    for (i = 0; i < N; i++)
    {
        cout << arr[i] << " ";                  //Printing array
    }
    return 0;
}