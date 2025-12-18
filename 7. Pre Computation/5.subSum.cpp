/*
    https://cses.fi/problemset/task/1660
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<long long> psum(n+1,0);
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        psum[i+1] = psum[i] + a;
    }
    int count = 0;
    int redu = 0;
    int i = 1;
    while(i <= n)
    {
        long long check = psum[i] - psum[redu];
        if(check > x) 
            redu++;
        else if(check==x)
        {
            count++;
            i++;
        }
        else
            i++;
    }
    cout << count << endl;
}