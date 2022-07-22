#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int,vector<int>,greater<int>> minHeap(arr.begin(),arr.begin()+K);
    for(int i=K; i<size; i++)
    {
        minHeap.push(arr[i]);
        minHeap.pop();
    }
    return minHeap.top();
}
