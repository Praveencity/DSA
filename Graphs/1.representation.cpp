#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
// Adjacency matrix
int graph1[N][N]; // Default Value 0
// Adjancency list
vector<pair<int,int>> graph2[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;

       graph1[v1][v2] = wt; 
       graph1[v2][v1] = wt; 

       graph2[v1].push_back({v2,wt});
       graph2[v2].push_back({v1,wt});
    }

    int i = 2, j = 5;

    if(graph1[i][j] >= 1)
    {
        //Connected
        cout << "Connected" << endl;
        cout << graph1[i][j] << endl;
    }

    for(auto &child:graph2[i])
    {
        if(child.first == j)
        {
            //Connected
            cout << "Connected" << endl;
            cout << child.second << endl;
        }
    }
    
}
// Adjancency matrix
// O(N^2) sc
// N = 10^5
// N != 10^5/ N <= 10^3

// Adjancency list
// O(N + E) sc
// N = 10^5 , E < 10^7