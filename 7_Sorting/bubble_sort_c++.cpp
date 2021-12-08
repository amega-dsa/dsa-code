//BUBBLE SORT CODE

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i, j, temp, flag; //Declaration of variables as integer
    cin >> N;
    int arr[N];             //Array named arr having size N
    for (i = 0; i < N; i++) //Takinng input
    {
        cin >> arr[i];
    }

    for (i = 0; i < N - 1; i++) // running this loop till N-1 becaue we need max N-1 trials to get our sorted array
    {
        flag = 0;
        for (j = 0; j < N - 1 - i; j++) // running this loop till N-1 because as no of traversal increases no of swapping decreases because last element starts occupying their correct places
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j]; //Swapping is done
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // This is done so as to minimise our steps as if in one trial we need 0 swapping that means we have got our sorted array so no need to sort it more.
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << "Sorted array using bubble sort is :" << endl;
    for (i = 0; i < N; i++)
    {
        cout << arr[i] << " "; //Printing sorted array
    }
    return 0;
}
