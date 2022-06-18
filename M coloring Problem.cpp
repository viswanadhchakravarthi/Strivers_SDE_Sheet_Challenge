bool possible(vector<vector<int>> &mat, int color,int nodesColors[],int n,int node)
{
    for(int adj_node=0; adj_node<n; adj_node++)
    {
        if(mat[node][adj_node]==1 && nodesColors[adj_node]==color)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &mat, int m,int nodesColors[],int n)
{
    for(int node=0; node<n; node++)
    {
        if(nodesColors[node]==0)
        {
            for(int color=1; color<=m; color++)
            {
                if(possible(mat,color,nodesColors,n,node))
                {
                    nodesColors[node] = color;
                    if(solve(mat,m,nodesColors,n))
                        return true;
                    nodesColors[node] = 0;
                }
            }
            return false;
        }
    }
    return true;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int nodesColors[n]={0};
    if(solve(mat,m,nodesColors,n))
        return "YES";
    else
        return "NO";
}
