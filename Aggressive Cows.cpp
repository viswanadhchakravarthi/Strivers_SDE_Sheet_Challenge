#include<bits/stdc++.h>
#include<algorithm>
bool check_gap(vector<int> positions,int n,int c,int dist)
{
    c--;
    int prev = 0;
    for(int i=1; i<n ; i++)
    {
        if(positions[i]-positions[prev] >= dist)
        {
            prev = i;
            c--;
        }
        if(c==0) return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
    int low = 1, high = positions[n-1]-positions[0];
    int res = -1;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(check_gap(positions,n,c,mid))
        {
            if(mid > res)
                res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
// Time: O(nlogn) + O( log(10^9) * n )
// Space: O(1)
