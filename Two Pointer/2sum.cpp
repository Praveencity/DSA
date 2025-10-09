#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    //vector<int> v(n);
    // for(auto &i:v) cin>>i;
    // map<int,int> mp;
    // for(int i=0;i<n;i++)
    // {
    //     int remain = x - v[i];
    //     if(mp.count(remain))
    //     {
    //         cout << i+1 << " " << mp[remain]+1 << endl;
    //         return 0;
    //     }
    //     mp[v[i]] = i;
    // }

    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back({a,i+1});
    }
    sort(begin(v),end(v));
    int i = 0,j=v.size()-1;
    while(i<j)
    {
        if(v[i].first + v[j].first == x)
        {
            cout << v[i].second << " " << v[j].second << endl;
            return 0;
        }
        if(v[i].first + v[j].first < x)
            i++;
        else
            j--;

    }
    cout << "IMPOSSIBLE" << endl;
}