#include <bits/stdc++.h>
using namespace std;

// ? TC : O(2^N) ? SC : O(N)
int fibonacci(int n){
    if(n==0 || n==1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// ? Adding Memoization ? TC : O(N) ? SC : O(N) 
int fibonacci(int n,vector<int> &dp){
    if(n==0 || n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}

int main(){
    int n = 5; // ? 0 1 1 2 3 5
    // Doing it just by recursion.
    cout << fibonacci(n) << endl;

    // Added Memoization
    vector<int> dp(n+1,-1);
    //cout << fibonacci(n,dp) << endl;

    // Tabulation (Iterative) without Space .
    // ? TC : O(N) ? SC : O(N)
    dp[0] = 0; dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;

    // Tabulation (Iterative) with Space Optimization.
    // ? TC : O(N) ? SC : O(1)
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    int a = 0,b = 1;
    for(int i=2;i<=n;i++){
        int c = a+b;
        a = b;
        b = c;
    }
    cout << b << endl;
    
}