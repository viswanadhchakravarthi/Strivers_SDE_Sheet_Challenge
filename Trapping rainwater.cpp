#include <bits/stdc++.h> 

// Brute Force: Time O(n), space: O(1)
// better : Time O(3n) ,space O(2n)
// below is optimal one with Time: O(n), Space: O(1)

long getTrappedWater(long *height, int n){
    long i=0,j=n-1;
    long water=0,lmax=0,rmax=0;
    while(i<=j){
        if(height[i]<=height[j]){
            if(lmax>height[i]) water += (lmax-height[i]); 
            else lmax= height[i];
            i++;
        }
        else{
            if(rmax>height[j]) water += (rmax-height[j]);
            else rmax = height[j];
            j--;
        }
    }
    return water;
}
