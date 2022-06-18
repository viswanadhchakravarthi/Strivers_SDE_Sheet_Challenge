// Solution 1: 

// Intuition: Using the concept of Backtracking, we will place Queen at different positions of the chessboard and find the right arrangement where all the n queens can be placed on the n*n grid.
// Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
// Space Complexity: O(N^2)

// Solution 2: 

// Intuition: This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.
// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N) 
  
void solve(int col,vector<vector<int>> &board, vector<vector<int>> &ans, int n,vector<int> &leftRow,vector<int> &lowerDiagnol,vector<int> &upperDiagnol)
{
    if( col==n )
    {
        vector<int> temp;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                temp.push_back(board[i][j]);
        ans.push_back(temp);
        return;
    }
    for(int row=0; row<n; row++)
    {
        if(leftRow[row]==0 && lowerDiagnol[row+col]==0 && upperDiagnol[(n-1)+(col-row)]==0)
        {
            board[row][col]=1;
            leftRow[row]=1;
            lowerDiagnol[row+col]=1;
            upperDiagnol[(n-1)+(col-row)]=1;
            
            solve(col+1,board,ans,n,leftRow,lowerDiagnol,upperDiagnol);
            
            board[row][col]=0;
            leftRow[row]=0;
            lowerDiagnol[row+col]=0;
            upperDiagnol[(n-1)+(col-row)]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans, board(n,vector<int>(n,0));
    
    vector<int> leftRow(n,0), lowerDiagnol(2*n-1,0), upperDiagnol(2*n-1,0);
    
    solve(0,board,ans,n,leftRow,lowerDiagnol,upperDiagnol);
    return ans;
}
