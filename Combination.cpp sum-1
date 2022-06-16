#include<algorithm>
void findCombination(vector<int>& candidates, int ind, int target, vector<vector<int>>& ans, vector<int>& ds)
{
    if( ind == candidates.size() ){
       if(target == 0)
           ans.push_back(ds); 
        return;
    }
    int ele = candidates[ind];
    ds.push_back(ele);
    findCombination(candidates,ind+1,target-ele,ans,ds);
    ds.pop_back();
    findCombination(candidates,ind+1,target,ans,ds);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    //sort(arr.begin(), arr.end());// here sort is NeedLess....
    
    findCombination(arr, 0, target, ans, ds);
    return ans;
}
// Time: O(2^t) for Rec-calls * O(k) for copying DS, where n is candidates.size() & O(2^n) is O(2^t)
// Space: Unpredictable depth of stack bcz we are choosing a coin unknown #times.
