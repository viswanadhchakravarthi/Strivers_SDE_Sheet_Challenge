#include<bits/stdc++.h>

long f(int val,int ind,int *denom, vector<vector<long>> &dp){
    // base case:
    if(ind==0 || val<0) return 0;
    if(val==0) return 1LL;
    if(dp[val][ind] != -1) return dp[val][ind];
    return dp[val][ind] = 
        f(val-denom[ind-1],ind,denom,dp) + f(val,ind-1,denom,dp);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    sort(denominations,denominations+n);
    vector<vector<long>> dp(value+1,vector<long>(n+1,0));
    
    for(int i=0; i<value+1; i++) dp[i][0] = 0; // if it reaches ind==0
    for(int j=0; j<n+1; j++) dp[0][j] = 1; // if val==0
    
    for(int v=1; v<=value; v++){
        for(int ind=1; ind<=n; ind++){
            dp[v][ind] += (v>=denominations[ind-1])? dp[v-denominations[ind-1]][ind] : 0;
            dp[v][ind] += dp[v][ind-1]; 
        }
    }
    return dp[value][n];  
}
