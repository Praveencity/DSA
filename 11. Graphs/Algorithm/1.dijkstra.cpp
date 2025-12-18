#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int INF = 1e9;
vector<pair<int,int>> g[N];
vector<int> wt(N,INF);

int dijkstra(int vertex, int target)
{
    multiset<pair<int,int>> s;
    s.insert({0,vertex});
    wt[vertex] = 0;

    while(!s.empty())
    {
        pair<int,int> node = *s.begin();
        s.erase(s.begin());
        if(node.first > wt[node.second]) continue;
        for(auto &i:g[node.second])
        {
            int new_wt = node.first + i.second;
            if(new_wt < wt[i.first] )
            {
                wt[i.first] = new_wt;
                s.insert({new_wt,i.first});
            }
        }
    }
    return wt[target];

}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g[v1].push_back({v2,wt});
        //g[v2].push_back({v1,wt}); if graph is undirected
    }
    int target;
    cin>>target;
    cout << dijkstra(1,target) << endl; 
}