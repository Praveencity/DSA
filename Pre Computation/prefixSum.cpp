/*
     https://judge.yosupo.jp/problem/static_range_sum
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> v(N);
    for(auto& x:v)
    {
        cin>>x;
    }
    
    vector<long long> psum(N+1);
    for(int i = 0;i<N;i++)
    {
        psum[i+1] = psum[i] + v[i];
    }

    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        cout << psum[r] - psum[l] << endl;
    }
}