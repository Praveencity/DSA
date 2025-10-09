#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(auto &i:v)
        cin >> i;
    
    long long sum = 0;
    int l = 0;
    int r = k-1;

    for(int i = 0;i<=r;i++) sum += v[i];
    long long tsum = sum;
    while(r<n-1)
    {
        tsum = tsum - v[l];
        l++;
        r++;
        tsum = tsum + v[r];
        sum = max(sum,tsum);
    }
    cout << sum << endl;
}