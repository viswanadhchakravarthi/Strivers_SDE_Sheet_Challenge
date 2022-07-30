int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
//     N -> #vertices
//     M -> #edges
    vector<int> dis(n+1,1e9);
    dis[src] = 0;
    for(int i=1; i<=n-1; i++)
    {
        for(auto &it:edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if(dis[u]!=1e9 and dis[u] + wt < dis[v])
                dis[v] = dis[u] + wt;
        }
    }
    // BellmanFord gaurantees that within n-1 relaxation , it can calculate shortest distance from 
    // source to other all vertices -> intuition is max(length_b/w_2_nodes)=n-1
    // in the nth relaxation if still dist decreases then it identifies that if a cycle exists
//     int f1=0;
//     for(auto &it:edges)
//         {
//             int u = it[0], v = it[1], wt = it[2];
//             if(dis[u] + wt < dis[v])
//             {
//                 f1=1;
//                 cout<<"negative cycle exists"<<endl;
//                 break;
//             }
//         }
//     if(f1==1)
//         return INT_MAX;
// it is gauranteed that there is no cycle, no need to relax for n th time
        return dis[dest];
}

// Time : O((n-1) * e) , if there's no -ve cycle
