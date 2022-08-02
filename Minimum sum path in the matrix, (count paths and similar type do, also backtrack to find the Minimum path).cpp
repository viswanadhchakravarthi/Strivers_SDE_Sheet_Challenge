#include<bits/stdc++.h>
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i==0 and j==0) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
        
    // move up or left
    int up = INT_MAX, left = INT_MAX;
    if(i-1>=0) up = f(i-1,j,grid,dp);
    if(j-1>=0) left = f(i,j-1,grid,dp);
    return dp[i][j] = grid[i][j] + min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0), cur(m,0);
    
    // base cases
    prev[0] = grid[0][0];
    for(int j=1; j<m; j++) prev[j] = grid[0][j] + prev[j-1];
    
    for(int i=1; i<n; i++){
        cur[0] = grid[i][0] + prev[0]; // calculate 0 th col of every row
        for(int j=1; j<m; j++){
            cur[j] = grid[i][j] + min(prev[j],cur[j-1]);
        }
        prev = cur;
    }
    return prev[m-1];
}

// Time: O(n*m) , Space: O(m)
