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
