bool checkCycle(int node,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) {
              if (checkCycle(it, vis, dfsVis, adj))
                  return true;
            } else if (dfsVis[it]) // default: vis[node]=1 from above if-case
              return true;
          }
        dfsVis[node] = 0;
        return false;
    }
int detectCycleInDirectedGraph(int N, vector < pair < int, int >> & edges) {
    //  'N' vertices and 'M' edges.
    vector<int> adjList[N+1]; // Graph_representation from 1 ..to.. N
    for(int j=0; j<edges.size(); j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j].first, node2 = edges[j].second;
        adjList[node1].push_back(node2); // one sided edge
    }
    vector<int> vis(N+1,0),dfsVis(N+1,0);
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            if(checkCycle(i,vis,dfsVis,adjList)) return true;
        }
    }
    return false;
}
