#include<bits/stdc++.h>
void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it,adj,vis,st);
    }
    st.push(node);
}
void revDfs(int node,vector<int> transpose[],vector<int> &vis,vector<int> &v)
{
    vis[node] = 1;
    v.push_back(node);
    for(auto it:transpose[node])
    {
        if(!vis[it])
            revDfs(it,transpose,vis,v);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n]; // Graph
    for(int i=0; i<edges.size(); i++)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> vis(n,0);
    stack<int> st; // get TopoSort into the stack( from top to bottom its topo-sort )
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i,adj,vis,st);
    }
    
    vector<int> transpose[n]; // we are reversing the edges, bcz to make components disconnected, which indeed look like connected while tarversing
    for(int i=0; i<n; i++)
    {
        vis[i]=0; // mark as unvisited , to traverse again
        for(auto it:adj[i])
            transpose[it].push_back(i);
    }
    
    vector<vector<int>> res;
    vector<int> traversal;
    while(!st.empty())
    {
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            revDfs(curr,transpose,vis,traversal); // this will not let traversal to other components
            res.push_back(traversal);
        }
        traversal.clear();
    }
    return res;
}
