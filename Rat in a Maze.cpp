void solve(vector<vector<int>> &maze, int n,int i,int j,vector<vector<int>> &visited,vector<vector<int>> &ans,vector<vector<int>> &directions)
{
    if(i==n-1 && j==n-1)
    {
        visited[i][j]=1;
        vector<int> tmp;
        for(vector<int> v:visited)
            tmp.insert(tmp.end(),v.begin(),v.end());
        ans.push_back(tmp);
        visited[i][j]=0;
        return;
    }
    for(int k=0; k<4; k++)
    {
        int nexti = i + directions[k][0];
        int nextj = j + directions[k][1];
        if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && maze[nexti][nextj]==1 && !visited[nexti][nextj])
        {
            visited[i][j]=1;
            solve(maze,n,nexti,nextj,visited,ans,directions);
            visited[i][j]=0;
        }
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    
    vector<vector<int>> ans, visited(n,vector<int>(n,0)), directions{{-1,0},{1,0},{0,1},{0,-1}};
    if(maze[0][0])
        solve(maze,n,0,0,visited,ans,directions);
    return ans;
}
