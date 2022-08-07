int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0, zerosCount=0, res=0;
    for(int j=0; j<n; j++){
        if(arr[j]==0)
            zerosCount++;
        while(zerosCount > k){
            if(arr[i]==0)
                zerosCount--;
            i++;
        }
        res = max( res, j-i+1);
    }
    return res;
}
// Time: O(n)
// Intuition is sliding window technique, 
// where window must contain atmost k 0's
