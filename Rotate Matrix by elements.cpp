void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0, col = 0; 
    int prev, curr; 
    int lastRow= n;
    int lastCol= m;
    while (row < lastRow && col < lastCol) 

    {  
        if (row + 1 == lastRow || col + 1 == lastCol)  break;   
        prev = mat[row + 1][col]; 
        //for the first row which is in bounds
        for (int i = col; i < lastCol; i++) 
        { 
            curr = mat[row][i]; 
            mat[row][i] = prev; 
            prev = curr; 
        } 
        row++; 
        //for the last column which is in bounds
        for (int i = row; i < lastRow; i++) 
        { 
            curr = mat[i][lastCol-1]; 
            mat[i][lastCol-1] = prev; 
            prev = curr; 
        } 
        lastCol--;   
        //for the last row which is in bounds
        if (row < lastRow) 
        { 
            for (int i = lastCol-1; i >= col; i--) 
            { 
                curr = mat[lastRow-1][i]; 
                mat[lastRow-1][i] = prev; 
                prev = curr; 
            } 
        } 
        lastRow--; 
        //for the first row which is in bounds
        if (col < lastCol) 
        { 
            for (int i = lastRow-1; i >= row; i--) 
            { 
                curr = mat[i][col]; 
                mat[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    } 
}

