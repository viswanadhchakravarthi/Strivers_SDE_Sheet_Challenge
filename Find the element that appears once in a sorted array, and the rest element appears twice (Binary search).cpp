// Approach 1: works only if sorted
//     for(int i=0; i<n;i++)
//     {
//         if((i+1==n || arr[i]!=arr[i+1]) && (i-1<0 || arr[i]!=arr[i-1]))
//             return arr[i];
//     }
//        this would fail if array is not sorted
//     return -1;
// Approach 2: simple works even if unsorted
//     int xr = 0;
//     for(int i=0; i<n; i++)
//     {
//         xr ^= arr[i];
//     }
//     return xr;

// Approach : Time: O(logn) Space: O(1)
int uniqueElement(vector<int> arr, int n)
{
    int low = 0, high = n-2;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(arr[mid]==arr[mid^1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[low];
}
