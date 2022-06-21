int search(int* arr, int n, int key) {
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(arr[mid]==key)
            return mid;
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=key && key<=arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if(arr[mid]<=key && key<=arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

// intuition behind using binary search is, definetly either left/right part of the mid will be in sorted order 
// Time: O(logn)
// Space: O(1)


