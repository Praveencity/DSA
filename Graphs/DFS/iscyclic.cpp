#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
vector<int> g[N];
vector<int> vis(N);

bool dfs(int vertex, int par)
{
    vis[vertex] = true;
    bool isLoopExists = false;
    for(int child:g[vertex])
    {
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        isLoopExists |= dfs(child,vertex);
    }
    return isLoopExists;
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

    bool isLoopExists = false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(dfs(i,0))
        {
            isLoopExists = true;
            break;
        } 
    }

    cout << isLoopExists << endl;
}