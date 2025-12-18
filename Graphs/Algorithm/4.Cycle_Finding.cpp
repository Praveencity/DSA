#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

struct Edge{
    int u,v,cost;
};

vector<Edge> edges;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<int> dist(n+1,0);
    vector<int> parent(n+1,-1);
    int x = -1;
    for(int i=0;i<n;i++)
    {
        x = -1;
        for(auto &e: edges)
        {
            if(dist[e.u] + e.cost < dist[e.v])
            {
                dist[e.v] = max(LLONG_MIN,dist[e.u]+e.cost);
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if(x==-1)
    {
        cout << "NO\n";
        return; 
    }

    vector<int> cycle;
    for(int i=0;i<n;i++)
        x = parent[x];
    int v = x;

    do{
        cycle.push_back(v);
        v = parent[v];
    }while(v!=x);

    cycle.push_back(x);
    reverse(cycle.begin(),cycle.end());

    cout << "YES\n";
    for(auto i:cycle)
        cout << i << ' ';
    cout << endl;
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
