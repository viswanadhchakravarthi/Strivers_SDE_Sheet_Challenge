#include<bits/stdc++.h>
int f(int eggs,int floors,vector<vector<int>> &dp){
    // if only one eggs is left , then in worst u have to check every floor
    if(floors<=1 or eggs==1) 
        return dp[eggs][floors] = floors;
    
    if(dp[eggs][floors]!=-1)
        return dp[eggs][floors];
    
    int mini = INT_MAX; // minimum no of trials needed (till having e eggs , f floors)
    // finding the critical floor
    
    int lo=1, hi=floors;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        
        int go_below = f(eggs-1,mid-1,dp); // egg break at mid  , floor left is mid-1
        int go_above = f(eggs,floors-mid,dp);// egg not break , no of floor left is f-mid
        
        // as we dont know egg will break or not
        // what we will do is we take the max no of trials from broken or not broken
        mini = min( mini, max( go_below, go_above));
        
        (go_above>go_below)? lo = mid+1 : hi = mid-1;
    }
    return dp[eggs][floors] = 1 + mini;
}

int cutLogs(int k, int n)
{
    // k == axes == eggs && n == log_stand_cap == floors
    vector<vector<int>> dp(k+1,vector<int>(n+1,-1));

    // Base cases:
    for(int eggs=1; eggs<=k; eggs++) {
        dp[eggs][0] = 0; // if floors == 0 [ BC ]
        dp[eggs][1] = 1; // if floors == 1 [ BC ]
    }
    // if only one eggs is left , then in worst u have to check every floor
    for(int floors=0; floors<=n; floors++)
        dp[1][floors] = floors; // if eggs == 1 [ BC ]
    
    for(int eggs=2; eggs<=k; eggs++){
        for(int floors=2; floors<=n; floors++){
            
            int mini = INT_MAX; // minimum no of trials needed (till having e eggs , f floors)
            // finding the critical floor

            int lo=1, hi=floors;
            while(lo<=hi){
                int mid = (lo+hi)/2;

                int go_below = dp[eggs-1][mid-1]; // egg break at mid  , floor left is mid-1
                int go_above = dp[eggs][floors-mid];// egg not break , no of floor left is f-mid

                // as we dont know egg will break or not
                // what we will do is we take the max no of trials from broken or not broken
                mini = min( mini, max( go_below, go_above));

                (go_above>go_below)? lo = mid+1 : hi = mid-1;
            }
            dp[eggs][floors] = 1 + mini;
        }
    }
    return dp[k][n];
}

// time: O(k * n * logn) , Space: O(n * k)
