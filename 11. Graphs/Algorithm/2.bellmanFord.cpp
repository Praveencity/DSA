#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

struct Edge{
    int a, b, cost;
};

void solve() {
    int n,m;
    cin>>n>>m;

    vector<Edge> edges;
    vector<int> dist(n+1,LLONG_MAX);
    dist[1] = 0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    for(int i=0;i<n-1;i++)
    {
        for(Edge &e : edges)
            if(dist[e.a]!=LLONG_MAX && dist[e.b] > dist[e.a]+e.cost)
                dist[e.b] = dist[e.a]+e.cost;
    }

    if(dist[n]==LLONG_MAX)
    {
        cout << -1 << endl;
        return;
    }

    for(Edge &e : edges)
    {
        if(dist[e.a]!=LLONG_MAX && dist[e.b] > dist[e.a]+e.cost)
        {
            cout << "Negative Cycle is Present\n";
            return;
        }
    }

    cout << dist[n] << endl;
}

int32_t main() {
    fast_io;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
