/*
    https://cses.fi/problemset/task/1643
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long> psum(n+1,0);
    for(int i = 0;i<n;i++)
    {
        long long x;
        cin>>x;
        psum[i+1] = psum[i] + x; 
    }
    long long maxi = psum[1];
    long long mini = psum[0];
    for(int i =1;i<=n;i++)
    {
        maxi = max(maxi,psum[i] - mini);
        mini = min(mini,psum[i]);
    }

    cout << maxi << endl;
}