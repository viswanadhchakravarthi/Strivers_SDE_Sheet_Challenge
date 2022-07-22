#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> res;
	  unordered_map<int,int> mpp; // ordered or unordered map is fine here, bcz both gives mpp.size()
    for(int j=0; j<k; j++)
        mpp[arr[j]]++;
    res.push_back(mpp.size());
    for(int j=k; j<arr.size(); j++)
    {
        if(--mpp[arr[j-k]] == 0) mpp.erase(arr[j-k]);
        mpp[arr[j]]++;
        res.push_back(mpp.size());
    }
    return res;
}
