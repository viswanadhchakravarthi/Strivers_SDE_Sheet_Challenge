#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
            // this case is self explanatory
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin(); 
            temp[ind] = arr[i];
            // this case is tricky, multiple conditions are hidden here
            // do a dry run to get clarity
            // anyhow we'll get max LIS length, but not LIS
        }
    }
    return len;
}

// Time: (n * log n)
// space: O(n)
