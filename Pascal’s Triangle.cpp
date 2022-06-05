vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> triangle;
  triangle.push_back({1});
        
  while(--n){
            vector<long long int> v;
            int k=triangle.size()-1;
            for(long long int i=-1,j=0; j<=triangle[k].size() ;i++,j++){
                long long int temp=0;
                if(i>=0)    temp += triangle[k][i];
                if(j<=triangle[k].size()-1)  temp += triangle[k][j];
                v.push_back(temp);
            } 
            triangle.push_back(v);
        }
  return triangle;
}

// Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).
// Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
