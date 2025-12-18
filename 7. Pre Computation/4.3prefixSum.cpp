/*
    https://usaco.org/index.php?page=viewproblem2&cpid=572
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> v(N);
    for(auto &x:v)
    {
        cin>>x;
    }
    vector<int> psum1(N+1);
    vector<int> psum2(N+1);
    vector<int> psum3(N+1);
    for(int i = 0;i<N;i++)
    {
        psum1[i+1] = psum1[i];
        psum2[i+1] = psum2[i];
        psum3[i+1] = psum3[i];
        if(v[i]==1)
            psum1[i+1]++;
        else if(v[i]==2)
            psum2[i+1]++;
        else if(v[i]==3)
            psum3[i+1]++;
    }

    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        cout << psum1[r] - psum1[l-1] << " ";  
        cout << psum2[r] - psum2[l-1] << " ";  
        cout << psum3[r] - psum3[l-1] << " " << endl; 
    } 
}