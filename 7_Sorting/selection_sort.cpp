//SELECTION SORT CODE

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i, j, minimum, temp; //Initialising values
    cin >> N;
    int arr[N];             //Array names arr of size N
    for (i = 0; i < N; i++) //Taking input
    {
        cin >> arr[i];
    }
    for (i = 0; i < N - 1; i++)
    {
        minimum = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[minimum]) //trying to find the minimum element in the array
            {
                minimum = j;
            }
        }
        if (minimum != i)
        {
            temp = arr[i];            //swapping is done
            arr[i] = arr[minimum];
            arr[minimum] = temp;
        }
    }
    cout << "Sorted array using Selection sort is:" << endl;
    for (i = 0; i < N; i++)
    {                                                      
        cout << arr[i] << " ";                        //Printing array
    }
    return 0;
}