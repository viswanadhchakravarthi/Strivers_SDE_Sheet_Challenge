class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> um;
        
        for(int i=0 ; i<nums.size() ; i++){
            
            if( um.find(target-nums[i]) != um.end()){
                ans.push_back(i);
                ans.push_back(um[target-nums[i]]);
                return ans;
            }
            um[nums[i]]=i;
        }
        return ans; // if no-pair exits , finally this returns empty pair
    }
};
// Time Complexity: O(n), Space : O(n)
// in worst time may goto O(n^2) bcz of unordered_map
