/*
    Author: Satyam Shukla
*/
#include <bits/stdc++.h>
using namespace std;
//Sieve of eratosthenes
//Time Complexity: - o(Nlog(log(N)))
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag()
{
    prime_flag[0] = prime_flag[1] = 1;
    for (i = 2; i < LIMIT; i++)
    {
        // to avoid overflow u can also set i*i<LIMIT
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
    //0 -> prime
    //1 -> not prime
}

//Segmented Sieve of Erothenes
////Time Complexity: - o(Nlog(log(N)))
int sieve[LIMIT+1];
void createSieve()
{ //SOE function used as a helful tool in Segmented Sieves
    for(int i=2;i<=LIMIT;i++)
        sieve[i]=1;
    
    for(int i=2;i*i<=LIMIT;i++)
    {
        //i*i to overcome the overflow
        if(sieve[i])
        {
            for(int j=i*i;j<=LIMIT;j++)
                sieve[j]=0;
        }
    }
}

//Function to generate and store the prime numbers in a given range
vector<int> generatePrimes(int N)
{
    vector<int> ans;
    for(int i=2;i<=N;i++)
    {
        if(sieve[i]==1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int32_t main()
{
    calculate_prime_flag();
    createSieve();
    //Enter the Number of Test Cases
    int T;
    cin>>T;
    while(T-->0)
    {
        cout<<"Enter a Number : ";
        int N;
        cin>>N;
        cout<<"Is "<<N<<" a Prime Number ? ";
        //0 - > Prime
        //1 -> Non Prime
        cout<<prime_flag[N]<<endl;
        int L,R;
        cin>>L>>R;
        vector<int> vp = generatePrimes(sqrt(R));
        int d[R-L+1];
        for(int i=0;i<R-L+1;i++)
        {
            d[i]=1;
        }
        for(auto &value:vp)
        {
            int firstMultiple = (L/value)*value;
            if(firstMultiple<L)
                firstMultiple+=value;
            
            for(int j=max(firstMultiple,value*value);j<=R;j+=value)
            {
                d[j-L]=0;
            }
        }
        for(int i=L;i<=R;i++)
        {
            if(d[i-L]==1)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}