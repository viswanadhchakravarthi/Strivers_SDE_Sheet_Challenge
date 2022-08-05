#include<bits/stdc++.h>

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>>res;
    int n = v.size();
    for(int num=0; num <= (1<<n)-1; num++){ // O(2^n)
        vector<int>tmp;
        for(int i=0; i<=n-1; i++){ // O(n)
            if(num & (1<<i))
                tmp.push_back(v[i]);
        }
        res.push_back(tmp);
    }
    return res;
}
