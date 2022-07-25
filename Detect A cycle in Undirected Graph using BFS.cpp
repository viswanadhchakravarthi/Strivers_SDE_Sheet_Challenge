#include<bits/stdc++.h>
// BFS
bool checkCycle(int node,int parent,vector<int> &vis,vector<int> adj[])
{
    queue<pair<int,int>> q;
    vis[node] = 1;
    q.push({node,parent});
    while(!q.empty())
    {
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it: adj[curr])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push({it,curr});
            } 
            else if(it!=par)
                return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int N, int M)
{
    //  'N' vertices and 'M' edges.
    vector<int> adjList[N+1]; // Graph_representation from 1 ..to.. N
    for(int j=0; j<M; j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j][0], node2 = edges[j][1];
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    vector<int> vis(N+1,0);
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            if(checkCycle(i,-1,vis,adjList)) return "Yes";
        }
    }
    return "No";
}
