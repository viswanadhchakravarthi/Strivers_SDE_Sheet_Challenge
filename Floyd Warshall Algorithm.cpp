int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // N : vertices && M : edges
    vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
    
    for(int it=1; it<=n; it++) adj[it][it] = 0;
    
    for(auto &it:edges)    adj[ it[0] ][ it[1] ] = it[2];

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj[i][k]!=1e9 && adj[k][j]!=1e9 && adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k]+adj[k][j];
            }
        }
    }
    return adj[src][dest];
}
// Floyd warshall's ==> all pair shortest path
// ********* Imp point to remember ******
// shortest path from i to j( which may / may not include k)
// d[i][j] = min( d[i][j] , d[i][k] + d[k][j])

// time: O( v * v^2) = O(v^3)
// space: O(v^2)


