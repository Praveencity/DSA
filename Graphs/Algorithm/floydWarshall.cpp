#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> dist(n+1,vector<int> (n+1,INF));

    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }


    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        //For multiple edges in same notes
        dist[x][y] = min(dist[x][y],wt);
    }


    //Main part
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] >= INF)  cout << "I ";
            else cout << dist[i][j] << ' '; 
        }
        cout << '\n';

    }
}