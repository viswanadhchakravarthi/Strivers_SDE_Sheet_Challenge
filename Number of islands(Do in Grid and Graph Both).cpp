
// Below soln is with GRID ,
// with GRAPH is nothing but finding no of isolated components, in a graph
void traverse(int** arr, int n, int m, int i, int j,int xdir[],int ydir[])
{
    if(i>=0 && j>=0 && i<n && j<m && arr[i][j]==1) 
    {
        arr[i][j] = -1; // just marking as visited for future reference
        // as i have placed above statement , after the below for loop, 
        // it costed stack overflow , so be carefull
        for(int d=0; d<8; d++)
        {
            traverse(arr,n,m, i+xdir[d], j+ydir[d], xdir, ydir);
        }
    }
}
int getTotalIslands(int** arr, int n, int m)
{
   int count = 0;
   int xdir[] = {-1,-1,-1,0,0,1,1,1};
   int ydir[] = {-1,0,1,-1,1,-1,0,1};
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(arr[i][j]==1){
               count++;
               //cout<<count<<endl;
               traverse(arr,n,m,i,j,xdir,ydir);
    }    }    }
    return count;
}

