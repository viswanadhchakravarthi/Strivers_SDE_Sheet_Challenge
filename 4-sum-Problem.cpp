class Solution {
public:
    void removeDuplicates(vector<int>& nums, int &ptr, bool l_to_r){
        if(l_to_r) while(ptr+1<nums.size() && nums[ptr]==nums[ptr+1]) ptr++;
        else       while(ptr-1>=0 && nums[ptr]==nums[ptr-1]) ptr--;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<=3) 
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1; j<nums.size() ; j++){
                int rem = target-nums[i]-nums[j], k = j+1, l=nums.size()-1;
                
                while(k < l){
                    if( nums[k]+nums[l]==rem ){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        removeDuplicates(nums,k,true),  k++;
                        removeDuplicates(nums,l,false), l--;
                    }
                    else if( nums[k]+nums[l] < rem) 
                        removeDuplicates(nums,k,true),  k++;
                    else                                 
                        removeDuplicates(nums,l,false), l--;
                } 
                // jumping over duplicates
                removeDuplicates(nums,j,true); //while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
            }
            // jumping over duplicates
            removeDuplicates(nums,i,true);     //while(i+1<nums.size() && nums[i]==nums[i+1]) i++;   
        }
        return ans;
    }
};
// Time Complexity: O(n^3) = O((n^2)*n) + O(nlogn) , Space Complexity: O(1)
