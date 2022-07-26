bool dfsBipartite(int node,vector<int> &vis,vector<vector<int>> &edges)
{
    if(vis[node]==-1)
        vis[node] = 0;
    for(int i=0; i<edges.size(); i++)
    {
        if(edges[node][i]==1)
        {
            if(vis[i]==-1){
                vis[i] = 1 - vis[node];
                if(!dfsBipartite(i,vis,edges))
                    return false;
            }
            else if(vis[i]==vis[node]) // vis[i]==1
                return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            edges[j][i] = edges[i][j];

    vector<int> vis(n,-1);
    for(int j=0; j<n; j++)
        if(vis[j]==-1 && !dfsBipartite(j,vis,edges))
                return false;   

    return true;
}
