class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=-1;
        int res=0;
        for(int i=0;i<=nums.size();i++){
            if(i==nums.size() || nums[i]==0){
                if(res < i-start-1)
                    res=i-start-1;
                start=i;
            }
        }
        return res;
    }
};
// O(n) time & constant space for both soln's
class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) 
                count++;
            else 
                count=0;
            maxi = max( maxi, count);
        }
        return maxi;
    }
};
