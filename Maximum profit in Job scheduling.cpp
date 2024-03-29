#include<bits/stdc++.h>
bool comparator(vector<int> a,vector<int> b) // must be static
{
    //return (a.profit>b.profit);
    return (a[1]>b[1]);
}
// Jobs[i][0] denote the deadline of i-th job and Jobs[i][1] denotes the profit associated with i-th job.
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comparator);
    int maxi=0;
    int n=jobs.size();
    for(int i=0; i<n; i++)
        maxi= max(jobs[i][0],maxi);
    
    int dead[maxi+1];
    memset(dead,-1,sizeof(dead));

    int count_jobs=0,max_prof=0;
    for(int j=0; j<n; j++)
    {
        for(int k=jobs[j][0]; k>0; k--)
        {
            if(dead[k]==-1)
            {
                dead[k]=1;
                count_jobs += 1;
                max_prof += jobs[j][1];
                break;
            }
        }
    }
    return max_prof;
}
