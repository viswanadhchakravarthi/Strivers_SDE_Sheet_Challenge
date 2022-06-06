void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                    swap(matrix[i][j],matrix[j][i]);
  
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        // intuition behind this algorithm is just make some observations how the given matrix
        // is getting changed to output.

        // 1) Transpose the given matrix.
        // 2) Reverse every row in the matrix.
        // Time: O(n^2) , Space : O(1)
}
