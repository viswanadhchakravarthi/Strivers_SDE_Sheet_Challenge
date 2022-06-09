#include <bits/stdc++.h> 
int findMajorityElement(int nums[], int n) {
    int count=0, maj;
    for(int i=0; i<n ; i++){
        // we are assuming the starting element as Maj , if count is 0
        if(count==0){
            // bcz we assume, before this count(maj) is balanced with count(others)
            maj=nums[i];
            count=1;
        }
        else{
            if(nums[i]==maj) count ++;
            // we increasing the count of Maj element
            else count--;
            // Balancing the count of majority elements with Other elements.
        }
    }
    count = 0;
    for(int i=0;i<n;i++)
        if(nums[i]==maj)
            count++;
    if(count>n/2)
        return maj;
    return -1;
}
// Time Complexity: O(n) Space Complexity : O(1)
// ******** Moore's Voting Algorithm *********
// Main intuition behind this algorithm is Majority element occurs >floor(N/2) times , where N: size of arr
