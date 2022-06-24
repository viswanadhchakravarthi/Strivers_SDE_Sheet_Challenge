#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    priority_queue<int> max_heap(arr.begin(), arr.begin()+k); // max heap
    priority_queue<int,vector<int>,greater<int>> min_heap(arr.begin(), arr.begin()+k); //min heap
    
    for(int j=k; j<n; j++)
    {
        max_heap.push(arr[j]);
        max_heap.pop();
        min_heap.push(arr[j]);
        min_heap.pop();
    }
    return {max_heap.top(),min_heap.top()};
}

// Time: O(k) + O( (n-k)*logk )
// Space: O(k)
