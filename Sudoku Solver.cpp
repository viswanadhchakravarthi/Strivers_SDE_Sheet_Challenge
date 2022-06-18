#include<bits/stdc++.h>
vector<int> row_col_block(int num)
{
    if(num<3)
        return {0,1,2};
    if(num<6)
        return {3,4,5};
    
    return {6,7,8};
}
bool isSafe(int matrix[9][9],int row,int col,int val)
{
    // each row & column
    for(int i=0; i<9; i++)
        if(matrix[row][i]==val || matrix[i][col]==val)
            return false;
    // 3 x 3 sub-matrices of the matrix.
    vector<int> row_block = row_col_block(row);
    vector<int> col_block = row_col_block(col);
    
    for(int i:row_block)
        for(int j:col_block)
            if(matrix[i][j]==val)
                return false;

    return true;
}
bool isSoduku(int matrix[9][9],int itr)
{
    if(itr==-1)
        return true;
    
    int row = itr/9, col = itr%9;
    
    if(matrix[row][col]!=0)
        return isSoduku(matrix,itr-1);
    
    for(int val=1; val<=9; val++)
    {
        if(isSafe(matrix,row,col,val))
        {
            matrix[row][col] = val;
            if(isSoduku(matrix,itr-1))
                return true;
            matrix[row][col] = 0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    int itr=80;
    return isSoduku(matrix,itr);
}
