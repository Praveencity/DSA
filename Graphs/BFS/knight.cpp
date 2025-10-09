// https://www.spoj.com/submit/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 8;

bool vis[N][N];
int lvl[N][N];

int x_cord(string &x)
{
    return x[0]-'a';
}
int y_cord(string &y)
{
    return y[1]-'1';
}

vector<pair<int,int>> steps = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}


int bfs(int x,int y, int tx, int ty)
{
    if (x == tx && y == ty) {
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = true;
    lvl[x][y] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto &i:steps)
        {
            int nx = i.first+x;
            int ny = i.second+y;
            if(!is_valid(nx,ny)) continue;
            if(vis[nx][ny]) continue;
            lvl[nx][ny] = lvl[x][y]+1;
            vis[nx][ny] = true;
            q.push({nx,ny});
            if (nx == tx && ny == ty)
                    return lvl[nx][ny];
        }
    }
    return -1;
}

void reset()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            vis[i][j] = false;
            lvl[i][j] = 0;
        }
    }
}

void solve() {
    string a,b;
    cin>>a>>b;
    reset();
    int x = x_cord(a);
    int y = y_cord(a);
    int tx = x_cord(b);
    int ty = y_cord(b);
    cout << bfs(x,y,tx,ty) << endl;
}

int32_t main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
