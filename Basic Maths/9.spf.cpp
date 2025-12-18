#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> prime(N+1);

int main()
{
    iota(prime.begin(),prime.end(),0);
    for(int i=2;i*i<=N;i++)
    {
        for(int j=i*i;j<=N;j+=i)
        {
            if(prime[j] == j)
                prime[j] = i;
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;


        //O(logn)
        while(n!=1)
        {
            cout << prime[n] << " ";
            n = n/prime[n];
        }
        cout << endl;

    }
}