void findSubsetSum(vector<int> &num,int itr,int sum,vector<int> &res)
{
    if(itr<0)
    {
        res.push_back(sum);
        return;
    }
    // pick-up the curr index
    findSubsetSum(num,itr-1,sum+num[itr],res);
    // do not pick-up the curr index
    findSubsetSum(num,itr-1,sum,res);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    findSubsetSum(num,num.size()-1,0,res);
    sort(res.begin(),res.end());
    return res;
}
// Time: O(2^N) for Recursion-calls + O( 2^N * log(2^N) ) for sorting
// Space: O(2^N) for sumSubset + O(N) for Recursion calls
