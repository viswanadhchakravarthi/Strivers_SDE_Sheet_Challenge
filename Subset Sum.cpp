#include<bits/stdc++.h>
bool f(int ind,int k, vector<int> &arr, vector<vector<int>> &dp){
    // base case:
    if(k==0) return 1;
    if(k<0 || ind<0) return 0;
    if(dp[ind][k]!=-1) return dp[ind][k];
    // not take or take
    return dp[ind][k] = f(ind-1,k-arr[ind],arr,dp) || f(ind-1,k,arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    
    for(int i=0; i<=n; i++) dp[i][0] = true; // k==0, then always ret true
    
    for(int ind=1; ind<=n; ind++){
        for(int val=1; val<=k; val++){
            if(val >= arr[ind-1])
                dp[ind][val] = dp[ind-1][val] or dp[ind-1][val-arr[ind-1]];
            else
                dp[ind][val] = dp[ind-1][val];
        }
    }
    return dp[n][k];
}
// Time: O(n*k) , Space: O(n*k)
