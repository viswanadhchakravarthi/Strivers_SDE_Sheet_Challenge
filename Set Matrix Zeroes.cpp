#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	    int m=matrix.size(),n=matrix[0].size();
        int col_1_status=1;
        for(int i=0;i<m;i++) if( matrix[i][0]==0) col_1_status=0;
        
        int row_1_status=1;
        for(int j=0;j<n;j++) if( matrix[0][j]==0) row_1_status=0;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = matrix[0][j] = 0;
                } 
            } 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(col_1_status==0){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
        if(row_1_status==0){
            for(int j=0;j<n;j++) matrix[0][j]=0;
        }
}
// Solution 1: Using brute force
// Intuition: O(N * M) for traversing through each element and (N+M)for traversing to row and column of elements having value 0.
// Time Complexity:O((N * M) * (N + M)). 
// Space Complexity:O(1)
	
// Solution 2: Better approach
// Intuition: Instead of traversing through each row and column, we can use dummy arrays to check if the particular row or column has an element 0 or not, which will improve the time complexity.

// Solution 3: Optimizing the better approach.
// Intuition: Instead of taking two dummy arrays we can use the first row and column of the matrix for the same work. This will help to reduce the space complexity of the problem.
// Time Complexity: O(2 * (N * M)), as we are traversing two times in a matrix,
// Space Complexity: O(1).
