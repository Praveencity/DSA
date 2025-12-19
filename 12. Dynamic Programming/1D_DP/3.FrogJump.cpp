/* 
TODO : Frog jump with K distances
https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances
 */

#include <bits/stdc++.h>
using namespace std;

// ? Done With Recursion and Memoization.
int rec(vector<int> &v,int i,int k,vector<int> &dp){
    if(i==0) return 0;
    if(dp[i] != -1)
        return dp[i];
    int mini = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i>=j)
            mini = min(mini,rec(v,i-j,k,dp) + abs(v[i]-v[i-j]));
    }
    return dp[i] = mini;
}

int frogJump(vector<int>& heights, int k) {
    vector<int> dp(heights.size(),-1);
    //return rec(heights,heights.size()-1,k,dp);

    // ? Tabulation(Iterative).
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i>=j)
                mini = min(mini,dp[i-j] + abs(heights[i]-heights[i-j]));
        }
        dp[i] = mini;
    }
    return dp[heights.size()-1];
}

int main(){
    vector<int> v = {15, 4, 1, 14, 15};
    cout << frogJump(v,3);
}