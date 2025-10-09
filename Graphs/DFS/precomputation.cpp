#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<int> sub_tree_sum(N);
vector<int> even_nums(N);

void tree_dfs(int vertex, int par = 0)
{
    if(!(vertex&1)) even_nums[vertex] = 1;
    sub_tree_sum[vertex] = vertex;
    for(auto child: g[vertex])
    {
        if(child == par) continue;
        tree_dfs(child, vertex);
        sub_tree_sum[vertex] += sub_tree_sum[child];
        even_nums[vertex] += even_nums[child];
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

    for(int i =1;i<=n;i++)
    {
        cout << i << " " << sub_tree_sum[i] << " " << even_nums[i] << endl;
    }
}