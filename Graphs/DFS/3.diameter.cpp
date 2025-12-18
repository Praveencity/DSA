#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<int> depth(N);

void dfs_tree(int vertex, int par = 0)
{
    for(int child:g[vertex])
    {
        if(child == par) continue;
        depth[child] = depth[vertex]+1;
        dfs_tree(child, vertex);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_tree(1);
    int maxi = depth[0];
    int max_node = 0;
    for(int i=1;i<=n;i++)
    {
        if(maxi < depth[i])
        {
            maxi = depth[i];
            max_node = i;
        }
    }

    fill(depth.begin(), depth.end(), 0); 
    dfs_tree(max_node);

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,depth[i]);

    cout << ans << endl;
    
}