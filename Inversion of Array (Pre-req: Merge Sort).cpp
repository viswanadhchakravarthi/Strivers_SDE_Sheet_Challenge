typedef long long int lli;
typedef long long ll;
lli merge(ll arr[],ll low,ll mid,ll high)
{
     // 1st array is upto mid
     // 2nd array is from mid+1

    ll n=high-low+1;
    ll temp[n];
    ll i=low , j=mid+1 , k=0 ;
    lli invCount=0;

    while( i<=mid && j<=high)
    {
        if(arr[i] <= arr[j]) temp[k++]=arr[i++]; // don't forget to keep <= in condition
             // bcz inversion means arr[i]>arr[j] when i<j.
        else                temp[k++]=arr[j++] , invCount += mid-i+1;
    }
    while( i<= mid )        temp[k++]=arr[i++];
    while( j<=high )        temp[k++]=arr[j++];

    k=0;  // to traverse over the temp array
    while( low <= high ) arr[low++]=temp[k++]; // low&high was not modified until now. so we can use it.

    return invCount;
}

lli mergeSort(ll arr[],ll left,ll right)
{
    lli invCount=0;
    if(left < right)
    {
        ll mid= left + (right-left)/2;
        invCount += mergeSort(arr,left,mid);
        invCount += mergeSort(arr,mid+1,right);

        invCount += merge(arr,left,mid,right); // here mid indicates end of the first array
    }
    return invCount;
}
long long int inversionCount(long long arr[], long long n)
{
    return mergeSort(arr,0,n-1);
}
// here Time : O(nlogn)
// we can solve this inversionCount Binary_Index_Tree in Time : O(n)

// alternative for counting inversions is using a reference variable concept.
