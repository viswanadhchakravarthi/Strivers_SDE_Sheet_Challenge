int nextGap(int gap)
    {
        if(gap==1)   // base condition should be return bcz (1/2)+(1%2) == 1
            return 0;
        return (gap/2)+(gap%2);
    }
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
          //step 1:
        int gap=m+n;
        
        for( gap=nextGap(gap) ; gap>0 ; gap=nextGap(gap) ){
         
            int i=0, j=gap;
            while( j<m+n ){
                
                if(i>=m && nums2[i-m] > nums2[j-m]) swap(nums2[i-m],nums2[j-m]);
                
                else if(i<m && j>=m && nums1[i] > nums2[j-m]) swap(nums1[i],nums2[j-m]);
                
                else if(  j<m && nums1[i] > nums1[j]) swap(nums1[i],nums1[j]);
                
                i++; j++;
            }
           }
        // step 2:
        for(int k=0; k<n ; k++) nums1[m+k]=nums2[k];
        
        return nums1;
}
