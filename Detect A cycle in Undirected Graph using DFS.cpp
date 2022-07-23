bool isCycle(int node, vector<int> adjList[], vector<char> &vis) // with DFS
{
    if(vis[node]=='b') // there exists a cycle, so return true.
        return true;
    if(vis[node]=='g')
        return false;
    else if(vis[node]='w')
        vis[node] = 'g';
    for(int nn : adjList[node]) // nn : neighbour_node
        if(isCycle(nn,adjList,vis))
            return true;
    vis[node] = 'b';
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
    vector<char> vis(N+1,'w'); // use graph to avoid confusion here
//     w - unvisited
//     g - processing
//     b - visited
    for(int i=1; i<=N; i++)
    {
        if(vis[i]=='w' and isCycle(i,adjList,vis))
            return "Yes";
        vis[i] = 'b';
    }
    return "No";
}
