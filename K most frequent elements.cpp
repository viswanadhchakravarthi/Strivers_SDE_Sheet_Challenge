#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    for(auto i:arr)
        mp[i]++;
    
    priority_queue<pair<int,int>> max_heap;
    for(auto it:mp)
        max_heap.push({it.second,it.first});
    
    vector<int> ans;
    while(k--)
    {
        ans.push_back(max_heap.top().second);
        max_heap.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
