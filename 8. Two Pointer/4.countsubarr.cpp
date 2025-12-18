#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &x:arr) cin>>x;

    int r=-1;
    long long sum = 0;
    int count = 0;

    for(int i=0;i<n;i++)
    {
        while(sum<=k && r<n-1)
        {
            if(sum == k)
                count++;
            r++;
            sum = sum + arr[r];
        }
        

        sum = sum - arr[i];   
    }

    cout << count << endl;
}