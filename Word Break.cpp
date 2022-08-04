#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & target) {
    if(arr.size()==0 and target.size()!=0)
        return false;
    
    unordered_map<string,int> mpp;
    for(auto &str : arr) mpp[str] = 1;
    
    vector<bool> dp(target.size()+1);
    dp[0] = true;
    for(int i=1; i<=target.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(dp[j]==true and mpp[target.substr(j,i-j)]==1){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[target.size()];
}
