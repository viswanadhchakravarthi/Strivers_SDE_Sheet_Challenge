#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	  vector<int> res;
    
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
    for(int i=0; i<n; i++)
    {
        max_heap.push(arr[i]);
        min_heap.push(arr[i]);
        if(max_heap.top()==arr[i] && min_heap.top()!=arr[i])
            max_heap.pop();
        else //if(max_heap.top() [!= or ==] arr[i] & min_heap.top()==arr[i])
            min_heap.pop();
        int diff = max_heap.size() - min_heap.size();
        if(diff <= -1) // diff -1 or -2
        {
            // move 1 ele from min_heap to max_heap
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if(diff == 2)
        {
            // move 1 ele from max_heap to min_heap
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
            
        if(max_heap.size() == min_heap.size())
            res.push_back((max_heap.top() + min_heap.top())>>1);
        else // always max_heap.size >= min_heap.size
            res.push_back(max_heap.top());
    }
    return res;
}
