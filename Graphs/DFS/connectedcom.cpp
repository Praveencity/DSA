#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
vector<int> g[N];
vector<vector<int>> cc;
vector<int> temp_vec;
bool vis[N];

void dfs(int vertex)
{
    vis[vertex] = true;
    temp_vec.push_back(vertex);
    for(auto child:g[vertex])
    {
        if(vis[child]) continue;
        dfs(child);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i = 1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count_connected = 0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        dfs(i);
        cc.push_back(temp_vec);
        temp_vec.clear();
        count_connected++;
    }
    cout << cc.size() << endl;

    for(vector<int> i:cc)
    { 
        for(int j:i)
            cout << j << " ";
        cout << endl;
    }
}