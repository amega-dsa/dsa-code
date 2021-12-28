#include <bits/stdc++.h>
using namespace std;
//Gcd Algorithms 
//Euclids Algorithm : - It is based on the formula gcd(a,b) = gcd(a-b,b) --> to reduce iterations we can say gcd(a,b) = gcd(a%b,b)
//Time Complexity := O(log(min(a,b)))
//Iterative Method
int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
//Recursive Algorithm
int gcd(int a,int b)
{
    //sole purpose is to make b zero
    if(b==0)
        return a;
    return gcd(b,a%b);
}