/*
    https://usaco.org/index.php?page=viewproblem2&cpid=595
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> v(N);
    for(auto& x:v)
    {
        cin>>x;
    }
    vector<long long> psum(N+1);
    // for(int i =0;i<N;i++)
    // {
    //     psum[i+1] = psum[i] + v[i];
    // }

    // for(auto& x:psum) x = x%7;
    v[0] %= 7;
    partial_sum(v.begin(),v.end(),psum.begin()+1,[](long long a,long long b){
        return (a+b)%7;
    });
    
    vector<int> first(7,-1);
    int maxi = 0;
    for(int i=0;i<=N;i++)
    {
        if(first[psum[i]] == -1) first[psum[i]] = i;
        else
        {
            int path = i - first[psum[i]];
            maxi = max(path,maxi); 
        }
    }
    
    cout << maxi << endl;

}