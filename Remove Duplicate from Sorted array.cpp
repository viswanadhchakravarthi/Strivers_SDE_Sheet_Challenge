int removeDuplicates(vector<int> &nums, int n) {
	//int n=nums.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}
// Optimal Soln, Time: O(2n) . Space: O(1)
