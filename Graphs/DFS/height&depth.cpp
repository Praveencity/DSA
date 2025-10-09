#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> g[N];
vector<int> depth(N); //From the Root to Node
vector<int> height(N);  //From Leaf to Node

void tree_dfs(int vertex, int par = 0)
{
    
    for(auto child: g[vertex])
    {
        if(child == par) continue;
        depth[child] = depth[vertex] + 1; 
        tree_dfs(child, vertex);
        height[vertex] = max(height[vertex],height[child]+1);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    tree_dfs(1);

    for(int i = 1;i<n;i++)
    {
        cout << "depth: " << depth[i] << " height: " << height[i] << endl;
    }
}