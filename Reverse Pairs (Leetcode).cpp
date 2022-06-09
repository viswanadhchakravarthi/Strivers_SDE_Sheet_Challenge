int merge(vector<int>& nums,int low,int mid,int high){
    // We assume mid as the ending of 1st array
    int total = 0;
    int y = mid+1;
    // Counting for Reverse Pairs
    for(int x=low ; x<=mid ; x++){
        while(y<=high && nums[x] > 2LL * nums[y]) 
            y++;
        total += (y - (mid+1));
    }

    // Merge Sort
    vector<int> temp(high-low+1,0);
    int i=low, j=mid+1, k=0;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]) temp[k++]=nums[i++];
        else                 temp[k++]=nums[j++];
    }
    while(i<=mid)            temp[k++]=nums[i++];
    while(j<=high)           temp[k++]=nums[j++];

    for(int p=low; p<=high ; p++) nums[p]=temp[p-low];

    return total;
}
int mergeSort(vector<int>& nums,int l,int h){
    //base case:
    if(l>=h) return 0;
    int mid=(l+h)/2;
    int invCount = 0;
    invCount += mergeSort(nums, l, mid);
    invCount += mergeSort(nums, mid+1, h);
    invCount += merge(nums,l,mid,h);
    return invCount;
}
int reversePairs(vector<int> &nums, int n){
    return mergeSort(nums, 0, nums.size()-1);
}
// Time Complexity: O( n logn ) , Space complexity: O(n) --> same as merge sort
// there is a small difference between day-3-6. Reverse Pairs( LeetCode ) and day-2-6. Inversion of Array (Pre-req: Merge Sort)
// bcz in previous problem given condition i<j & arr[i]>arr[j] and default merging conditions can be written in same for loop ,
// unlike this problem.
