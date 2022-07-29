vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    for(int i=0; i<edges; i++)
    {
        int a=vec[i][0] , b=vec[i][1], dis=vec[i][2];
        adj[a].push_back({b,dis});
        adj[b].push_back({a,dis});
    }
    vector<int> visited(vertices,INT_MAX);
    visited[source] = 0;
    typedef pair<int,int> pr;
    priority_queue<pr,vector<pr>,greater<pr>> q; //min_heap
    q.push({0,source});
    while(!q.empty()){
        auto curr = q.top();
        q.pop();
        int sdist = curr.first;
        int node = curr.second;
        for(auto it:adj[node])
        {
            int nxt = it.first;
            int wt = it.second;
            if(sdist + wt < visited[nxt])
            {
                visited[nxt] = sdist + wt;
                q.push({visited[nxt],nxt});
            }
        }
    }
    return visited;
}
// time: O( (v+e)logv ) , Space: O( v + v)
