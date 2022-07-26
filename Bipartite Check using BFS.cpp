#include<bits/stdc++.h>

bool bfsBipartite(int node,vector<int> &vis,vector<vector<int>> &edges)
{
    queue<int> q;
    q.push(node);
    vis[node] = 0; // initial color = 0
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i=0; i<edges.size(); i++)
        {
            if(edges[curr][i]==1)
            {
                if(vis[i]==-1){
                    q.push(i);
                    vis[i] = 1 - vis[curr];
                }
                else if(vis[i]==vis[curr]) // vis[i]==1
                    return false;
            }
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
        if(vis[j]==-1 && !bfsBipartite(j,vis,edges))
            return false;
    return true;
}
