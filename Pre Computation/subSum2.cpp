#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long  x;
    cin>>n>>x;
    map<long long,int> mp;
    mp[0] = 1;
    long long c_sum = 0;
    long long count = 0;

    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        c_sum = a + c_sum;
        
        long long r_psum = c_sum - x;

        if(mp.count(r_psum))
        {
            count += mp[r_psum];
        }

        mp[c_sum]++;
    }

    cout << count << endl;

}