#include<bits/stdc++.h>
// int f(int ind,int w,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
//     if(ind == 0){
//         if(wt[ind] <= w) return val[ind];
//         else return 0;
//     }
//     if(dp[ind][w]!=-1) return dp[ind][w];
//     int notTake = 0 + f(ind-1,w,wt,val,dp);
//     int take = INT_MIN;
//     if(wt[ind] <= w){
//         take = val[ind] + f(ind-1,w-wt[ind],wt,val,dp);
//     }
//     return dp[ind][w] = max(notTake,take);
// }
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    vector<int> prev(W+1,0);
    
    for(int w=wt[0]; w<=W; w++) prev[w] = val[0];
	
    for(int ind=1; ind<n; ind++){
        for(int w=W; w>=0; w--){ // reversed direction, still works
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(wt[ind] <= w){
                take = val[ind] + prev[w-wt[ind]];
            }
            prev[w] = max(notTake,take);
        }
    }
    return prev[W];
}
// Time: O(n*W) , Space: O(W)
