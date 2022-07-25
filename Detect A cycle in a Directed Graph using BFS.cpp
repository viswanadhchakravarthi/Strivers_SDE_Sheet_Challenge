#include<bits/stdc++.h>
// Kahn's algorithm ( similar to BFS but a topological sort algorithm )
int detectCycleInDirectedGraph(int N, vector < pair < int, int >> & edges) {
    //  'N' vertices and 'M' edges.
    vector<int> adjList[N+1]; // Graph_representation from 1 ..to.. N
    vector<int> inDegree(N+1,0);
    for(int j=0; j<edges.size(); j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j].first, node2 = edges[j].second;
        adjList[node1].push_back(node2); // one sided edge
        inDegree[node2]++;
    }
    queue<int> q; // contains nodes whose inDegree is zero
    for(int it=1; it<=N; it++)
        if(inDegree[it]==0)
            q.push(it);
    int count = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for(auto it : adjList[curr])
        {
            inDegree[it]--;
            if(inDegree[it]==0)
                q.push(it);
        }
    }
    if(count == N) // if all nodes are in Topo-sort then , there's no cycle
        return 0;
    else
        return 1;   
}
 
