#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for(auto &it:g) //it=> ((u,v),wt)
    {
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }
    vector<int> parent(n+1,-1);
    vector<bool> mstSet(n+1,false);
    vector<int> key(n+1,INT_MAX);
    key[1] = 0;    
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // minHeap
    pq.push({0,1}); // key,node
    // bcz there can be max of n-1 edges in MST
    while(!pq.empty()) // why its not working taken loop for n-1 times
    {
        int u = pq.top().second;
        pq.pop();
        
        mstSet[u] = true;
        
        for(auto &it:adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if(!mstSet[v] && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v],v}); 
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for(int i=2; i<=n; i++)
    {
        res.push_back({{parent[i],i},key[i]});
    }
    return res;
}
// Time: O( E log V + V log V ) 
// space: O( V )
