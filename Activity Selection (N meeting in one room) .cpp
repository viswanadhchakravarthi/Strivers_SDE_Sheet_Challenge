    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // static bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b)
    // {
    //     return (a.second < b.second);
    // }
#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    vector<pair<pair<int,int>,int>> v;
    int n = start.size();
    vector<int> res;
    //if(n==39553)
        
    for(int i=0;i<n;i++)
        v.push_back({{start[i],end[i]},i+1});
    //sort(v.begin(),v.end(),sortBySecond);
    // we can use above comparator(must be static) func 
    // or Lambda func like below....
    sort(v.begin(),v.end(),
         [](const pair<pair<int,int>,int> a,const pair<pair<int,int>,int> b){
             if(a.first.second<b.first.second)
                 return true;
             else if(a.first.second==b.first.second && a.second<b.second)
                 return true;
             else
                 return false;
         });
    int curr_time = -1;
    //int count=0;
    for(int j=0;j<v.size();j++)
    {
        if(v[j].first.first >= curr_time) // added >= instead of >
        {
            //count++;
            res.push_back(v[j].second);
            curr_time = v[j].first.second;
        }
    }
    //sort(res.begin(),res.end());
    return res.size(); 
}
// time: O(nlogn) for sort 
// Space: O(n) for_sort/vector<pairs>
