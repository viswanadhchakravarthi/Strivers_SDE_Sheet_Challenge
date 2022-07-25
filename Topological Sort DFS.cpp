#include<bits/stdc++.h>

// before applying this algorithm make sure the graph is DAG( directed acyclic graph ),
// otherwise , it will produce some wrong topoSort even if cycle exists

void topoDFS(int node, vector<int> &vis, stack<int> &st,vector<int> adj[])
{
    vis[node] = 1;
    for(auto i : adj[node])
    {
        if(!vis[i])
            topoDFS( i, vis, st, adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //  'N' vertices and 'M' edges.
    vector<int> adjList[v]; // Graph_representation from 1 ..to.. N
    for(int j=0; j<e; j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j][0], node2 = edges[j][1];
        adjList[node1].push_back(node2); // one sided edge
    }
    stack<int> st;
    vector<int> vis(v,0);
    for(int it=0; it<v; it++)
    {
        if(!vis[it])
        {
            topoDFS(it,vis,st,adjList);
        }
    }
    vector<int> topoSort;
    // pop(LIFO) all elements and push into topoSort . this works
    // bcz, every node says i will enter into the stack only after all my descendants are processed
    while(!st.empty())
    {
        topoSort.push_back(st.top());
        st.pop();
    }
    return topoSort;
}
