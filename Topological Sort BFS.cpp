#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //  'N' vertices and 'M' edges.
    vector<int> adjList[v]; // Graph_representation from 1 ..to.. N
    vector<int> inDegree(v,0);
    for(int j=0; j<e; j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j][0], node2 = edges[j][1];
        adjList[node1].push_back(node2); // one sided edge
        inDegree[node2]++;
    }
    queue<int> q; // contains nodes whose inDegree is zero
    for(int it=0; it<v; it++)
        if(inDegree[it]==0)
            q.push(it);
    
    vector<int> topoSort;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        topoSort.push_back(curr);
        for(auto it : adjList[curr])
        {
            inDegree[it]--;
            if(inDegree[it]==0)
                q.push(it);
        }
    }
    return topoSort; 
}
