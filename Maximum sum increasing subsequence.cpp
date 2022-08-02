int f(int ind,int prev_ind,vector<int> &arr,int n,vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
    int sum = 0 + f(ind+1,prev_ind,arr,n,dp);
    if(prev_ind == -1 || arr[ind]>arr[prev_ind])
        sum = max( sum, arr[ind] + f(ind+1,ind,arr,n,dp));
    return dp[ind][prev_ind+1] = sum;
}
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}
