vector<int> majorityElementII(vector<int> &nums)
{
    int ele1=-1, ele2=-1, c1=0, c2=0;
        for(int i=0; i<nums.size() ; i++){
            if(nums[i]==ele1) 
                c1++;
            else if(nums[i]==ele2) 
                c2++;
            else if(c1==0){
                ele1=nums[i];
                c1++;
            }
            else if(c2==0){
                ele2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0, c2=0;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==ele1) c1++;
            else if(nums[i]==ele2) c2++;
        }
        vector<int> ans;
        int base_count= nums.size()/3;
        if(c1>base_count) ans.push_back(ele1);
        if(c2>base_count) ans.push_back(ele2);
        
        return ans;

}
// Time complexity: O(n) , Space complexity: O(1)
// ******* Extended Boyer Moore’s Voting Algorithm *******
// intuition behind this almost same as Majority Element( > N / 2) times , 
// there are total 3 kind with count1 , count2 and others 
// and we are trying to nuetralize all the 3 kinds & at last whichever has a +ve count
// those are the majority elements of the array.
