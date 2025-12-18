#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> prime(n+1,1);

    //Time complexity of the Sieve of Eratosthenes is O(nlog(logn)).
    for(int i=0;i*i<=n;i++)
    {
        if(i== 0 || i==1)
            prime[i] = 0;
        if(prime[i]==1)
        {
            for(int j = i*i;j<=n;j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
            cout << i << endl;
    }
}