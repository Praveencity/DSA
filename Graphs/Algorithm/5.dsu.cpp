#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> parent(N,0), sz(N,0);

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if(parent[v] == v)
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a!=b)
    {
        if(sz[a] < sz[b])
            swap(a,b);
        
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        make_set(a);
    }

    union_sets(1, 2);
    union_sets(3, 4);
    union_sets(1, 3);

    cout << find_set(4) << endl;
}