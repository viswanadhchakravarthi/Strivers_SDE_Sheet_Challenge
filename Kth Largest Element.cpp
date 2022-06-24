#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int> max_heap; // max heap
    priority_queue<int,vector<int>,greater<int>> min_heap;//min heap
    
    for(int i=0; i<k; i++)
    {
        max_heap.push(arr[i]);
        min_heap.push(arr[i]);
    }
    for(int j=k; j<n; j++)
    {
        max_heap.push(arr[j]);
        max_heap.pop();
        min_heap.push(arr[j]);
        min_heap.pop();
    }
    return {max_heap.top(),min_heap.top()};
}
// Time: O(klogk) + O( (n-k) log k )
// Space: O(k)
