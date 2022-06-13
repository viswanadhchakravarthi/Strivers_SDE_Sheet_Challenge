#include <bits/stdc++.h> 

// worst case- Time:O(n^3) and Space:O(1)
// below is optimal solution
void removeDuplicates(vector<int>& nums, int &ptr, bool l_to_r){
        if(l_to_r) while(ptr+1<nums.size() && nums[ptr]==nums[ptr+1]) ptr++;
        else       while(ptr-1>=0 && nums[ptr]==nums[ptr-1]) ptr--;
}
vector<vector<int>> findTriplets(vector<int> nums, int n, int K) {
	int sum;
    //int n=nums.size();
    vector<vector<int>> ans;
    if(n<3) 
        return ans;
    sort(nums.begin(),nums.end());
    for(int j=0 ; j<n ; j++){
        int rem = K-nums[j], k = j+1, l=nums.size()-1;

        while(k < l){
            if( nums[k]+nums[l]==rem ){
                ans.push_back({nums[j],nums[k],nums[l]});
                removeDuplicates(nums,k,true),  k++;
                removeDuplicates(nums,l,false), l--;
            }
            else if( nums[k]+nums[l] < rem) 
                removeDuplicates(nums,k,true),  k++;
            else                                 
                removeDuplicates(nums,l,false), l--;
        } 
        // jumping over duplicates
        removeDuplicates(nums,j,true);
    }
    return ans;
}
// Time: O(n^2)+O(nlogn) , Space: O(1)
