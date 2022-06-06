vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    //no need to use any additional data-structures like Stack.
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size()==0){
            return mergedIntervals;
        }
        
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];
        
        for(auto it:intervals){
            if(tempInterval[1] >= it[0]){
                tempInterval[1] = max(tempInterval[1],it[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
}
// Time : O(nlogn + n) for Sorting & traversing
// Space : O(n) to store results.

