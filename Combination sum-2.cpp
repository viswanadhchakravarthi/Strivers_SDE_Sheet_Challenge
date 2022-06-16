#include<algorithm>
void find_uniq_comb(vector<int>& arr,int itr,int target,vector<vector<int>>& res,vector<int>& ds)
{
    if(target==0)
    {
        res.push_back(ds);
        return;
    }
    if(itr<0)
        return;
    for(int i=itr; i>=0; i--)
    {
        if(i!=itr && arr[i]==arr[i+1])
            continue;
        ds.push_back(arr[i]);
        find_uniq_comb(arr,i-1,target-arr[i],res,ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> res;
    vector<int> ds;
	sort(arr.begin(),arr.end(),greater<int>());
    find_uniq_comb(arr,n-1,target,res,ds);
    return res;
}
