/* 
TODO : Frog jump with K distances
https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances
 */

#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> &v,int i,int k){
    if(i==0) return 0;
    
    int mini = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i>=j)
            mini = min(mini,rec(v,i-j,k) + abs(v[i]-v[i-j]));
    }
    return mini;
}

int frogJump(vector<int>& heights, int k) {
    return rec(heights,heights.size()-1,k);
}

int main(){
    vector<int> v = {15, 4, 1, 14, 15};
    cout << frogJump(v,3);
}