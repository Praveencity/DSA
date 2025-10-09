/*
    https://codeforces.com/contest/279/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(auto &x:v) cin>>x;

    int sum = 0;
    int ans = 0;
    int l = 0;
    for(int r = 0;r<n;r++)
    {
        sum = sum + v[r];

        while(l<=r && sum > t)
        {
            sum  = sum - v[l];
            l++;
        }

        ans = max(r-l+1,ans);

    }

    cout << ans << '\n';

}