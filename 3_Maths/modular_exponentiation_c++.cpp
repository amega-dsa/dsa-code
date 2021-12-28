/*
    Author: - Satyam Shukla
*/
#include <bits/stdc++.h>
using namespace std;
//Modular Exponentiation :- it is required because normal power function time complexity is O(n)
//This Algorithm reduces the Time Complexity to O(log(n))
//Based on the Realation
//For odd n --> (x^n)%m = (x^(n/2))^2*x
//For Even n --> (x^n)%m = (x^(n/2))^2
int modularExponentiation(int x,int n,int m)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
        {
            res = (1LL*(res%m)*(x%m))%m;
        }
        x=(1LL*(x%m)*(x%m))%m;
        n>>=1;
    }
    return res;
}