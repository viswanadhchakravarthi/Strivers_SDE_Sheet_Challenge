int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> us(arr.begin(),arr.end()); // O(n)
//     for(int i:arr)    us.insert(i);
    int global_max=0;
    for(int i:arr)  // O(n)
    {
        int local_max=0;
        if(us.find(i-1)==us.end())
        {
            while(us.find(i)!=us.end())    // cummulative complexity : O(n)
            {
                i++;
                local_max++;
            }
            global_max = max( global_max, local_max);
        }
    }
    return global_max;
}
// Time Complexity : O(n + n + n) = O(n) , Space Complexity: O(n)
