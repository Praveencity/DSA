#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> g[N];
vector<int> paren(N);


void tree_dfs(int vertex, int par = 0)
{
    paren[vertex] = par;
    for(auto child: g[vertex])
    {
        if(child == par) continue;
        tree_dfs(child, vertex);
    }
}

vector<int> parents(int vertex)
{
    vector<int> temp;
    while(vertex)
    {
        temp.push_back(paren[vertex]);
        vertex = paren[vertex];
    }
    reverse(temp.begin(),temp.end());
    return temp;
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
    int a,b;
    cin>>a>>b;
    vector<int> par_a =  parents(a);
    vector<int> par_b =  parents(b);
    int ans = 0;
    for(int i=0;i<min(par_a.size(),par_b.size());i++)
    {
        if(par_a[i] != par_b[i])
            break;
        ans = par_a[i];
    }

    cout << ans << endl;
}