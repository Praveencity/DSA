#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> g[N];
vector<bool> vis(N);

// Time Complexity O(N+E)
void bfs(int vertex)
{
    queue<int> qu;
    qu.push(vertex);
    vis[vertex] = true;
    while(!qu.empty())
    {
        int par = qu.front();
        qu.pop();
        cout << par << " ";
        for(auto child:g[par])
        {
            if(vis[child]) continue;
            vis[child] = true;
            qu.push(child);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bfs(1);
}

