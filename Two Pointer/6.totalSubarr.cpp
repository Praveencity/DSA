// https://codeforces.com/contest/2148/problem/E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


void solve() {
    int n,k;
    cin>>n>>k;
    map<int,int> m;
    vector<int> v; 
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        m[a]++;
        v.push_back(a);
    }


    for(auto &i:m)
    {
        if(i.second%k != 0)
        {
            cout << 0 << endl;
            return;
        }
    }

    //Main Concept
    int ans = 0;
    map<int,int> mp;
    int r = -1;
    for(int i=0;i<n;i++)
    {
        while(r+1<n && mp[v[r+1]] < m[v[r+1]]/k )
        {
            mp[v[r+1]]++;
            r++;
        }
        //Counting the number of subarray
        ans += (r-i+1);
        mp[v[i]]--;
    }
    cout << ans << endl;

}

int32_t main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
