#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    long long ans = 1;
    // O(logx)
    while(x>0)
    {
        if(x%2==1)
        {
            ans *= n;
            x = x-1;
        }
        else
        {
            n *= n;
            x /= 2;
        }
    }
    cout << ans << endl;
}