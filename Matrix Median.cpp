#include<bits/stdc++.h>

int upper_bound(vector<int> &row, int mid)
{
    int l = 0, h = row.size()-1;
    while(l<=h)
    {
        int md = l + ((h-l)>>1);
        //int md = (l + h) >> 1;
        if(row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int low = 0, high = 1e9;
    int n = matrix.size(), m = matrix[0].size();
    while(low<=high)
    {
        int mid = low + ((high-low)>>1);
        //int mid = (low + high) >> 1;
        int count = 0;
        for(auto &row:matrix)
        {
            count += upper_bound(row,mid);
        }
        if(count <= (n*m)>>1)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

// Time: log2 ( 2^32 ) * (n log2 m) 
//          = O(32 n log2(m) )
// Space: O(1)
