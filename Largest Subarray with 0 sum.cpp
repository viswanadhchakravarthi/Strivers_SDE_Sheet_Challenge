int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> mpp;
    mpp[0] = -1;   
    // since we are not standing at any index, assume it as zero
    // there's an reason also while calculating length this '-1' helps
    // in calculating the length accurately....
    int sum = 0,length=0;
    for(int i=0; i<arr.size(); i++)
    {
        sum += arr[i];
        if(mpp.find(sum)!=mpp.end())
        {
            length = max( length, i-mpp[sum] );
        }
        else{
            mpp[sum]=i;
        }
    }
    return length;
}
// Time complexity: O(n) bcz for unordered_map->avg tc is O(1) for any operation
// Space complexity: O(n) in worst case & average
