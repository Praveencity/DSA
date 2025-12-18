#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> prime(N+1,1);

int main()
{
    //  O(Nlog(logN)+q)

    for(int i= 0;i*i<=N;i++)
    {
        if(i==0 || i==1) prime[i] = 0;
        if(prime[i] == 1)
        {
            for(int j = i*i;j<=N;j+=i)
            {
                prime[j] = 0;
            }
        }
    }

    for(int i=2;i<=N;i++)
    {
        prime[i] = prime[i] + prime[i-1];
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout << prime[r] - prime[l-1] << endl;
    }
}