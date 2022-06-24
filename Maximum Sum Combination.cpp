#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> max_heap;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            max_heap.push(a[i]+b[j]);
        }
    }
    vector<int> res;
    while(k--)
    {
        res.push_back(max_heap.top());
        max_heap.pop();
    }
    return res;
}
