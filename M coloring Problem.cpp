bool possible(vector<vector<int>> &mat, int color,int nodesColors[],int n,int node)
{
    for(int adj_node=0; adj_node<n; adj_node++)
    {
        if( adj_node!=node && mat[node][adj_node]==1 && nodesColors[adj_node]==color)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<vector<int>> &mat, int m,int nodesColors[],int n)
{
    if(node==n)
        return true; 
    for(int color=1; color<=m; color++)
    {
        if(possible(mat,color,nodesColors,n,node))
        {
            nodesColors[node] = color;
            if(solve(node+1,mat,m,nodesColors,n))
                return true;
            nodesColors[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int nodesColors[n]={0};
    if(solve(0,mat,m,nodesColors,n))
        return "YES";
    else
        return "NO";
}

// Time: O(n^m) where n is #nodes && m is #colors
// Space: O(n) bcz at max the depth of the stack is #nodes
