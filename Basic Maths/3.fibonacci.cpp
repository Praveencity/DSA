#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;


int main()
{
    long long n;
    cin>>n;
    int a = 0;
    int b = 1;
    for(long long i = 2;i<=n;i++)
    {
        long long c = (a+b)%M;
        a = b;
        b = c;
    }
    if(n == 0 || n == 1) cout << n << endl;
    else cout << b << endl;
    
}