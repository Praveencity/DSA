/*
    https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

    6 15
    10 5 2 7 1 -10
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<long long,int> pre_sum;
    long long sum = 0;
    int len = 0;
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        sum += a;
        if(sum == k)
            len  = max(len,i + 1);

        long long resum = sum - k;
        if(pre_sum.count(resum))
            len = max(len,i - pre_sum[resum]);
        
        if(pre_sum.count(sum) == 0)
            pre_sum[sum] = i;
    }
    cout << len << endl;
}