#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> tmp;
    for(int i=0; i<k; i++) tmp.push_back(kArrays[i][0]);
    priority_queue<int,vector<int>,greater<int>> min_heap(tmp.begin(),tmp.end());
    for(int i=0; i<k; i++)
    {
        for(int j=1; j<kArrays[i].size(); j++)
        {
            min_heap.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while(!min_heap.empty())
    {
        res.push_back(min_heap.top());
        min_heap.pop();
    }
    return res;
}

// Time: O(k) + O( (nk-k * logk )
// space: O(n)
