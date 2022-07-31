int maximumProduct(vector<int> &arr, int n)
{
	int ma = arr[0], mi = arr[0], res = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<0) 
            swap(ma,mi);
        ma = max(ma*arr[i],arr[i]);
        mi = min(mi*arr[i],arr[i]);
        res = max(res,ma);
    }
    return res;
}
// Time: O(n) , Space: O(1)
