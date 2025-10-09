#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &x:arr) cin>>x;

    int maxlen = 0;
    
    //int r=-1;
    long long sum = 0;
    // for(int i=0;i<n;i++)
    // {
    //     while(sum<=k && r<n-1)
    //     {
    //         maxlen = max(maxlen,r-i+1);
    //         r++;
    //         sum = sum + arr[r];
    //     }  

    //     sum = sum - arr[i];
    // }
    int r = 0;
    int l = 0;
    while(r<n)
    {
        sum = sum + arr[r]; // If ask length or then while loop
        if(sum > k)
        {
            sum = sum - arr[l];
            l++;
        }

        if(sum <=k)
            maxlen = max(maxlen,r-l+1);
        r++;
    }

    cout << maxlen << endl;

}