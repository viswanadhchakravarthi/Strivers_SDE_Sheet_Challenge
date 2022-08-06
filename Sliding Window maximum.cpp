#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> res;
    deque<int> dq; // stores in decrement order
    for(int i=0; i<nums.size(); i++){
        // popping out of bound element( old ) from DeQueue
        if(!dq.empty() and dq.front()==i-k)
            dq.pop_front();
        // remove small elements to push new element into DeQueue
        while(!dq.empty() and nums[dq.back()]<nums[i])
            dq.pop_back();
        dq.push_back(i);
        
        if(i>=k-1)
            res.push_back(nums[dq.front()]);
    }
    return  res;
}
// Time: O(n) for traversal + O(n) for deque ops
// space: O(k) at max to store elements in deque
