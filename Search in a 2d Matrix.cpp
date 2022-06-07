class Solution {
public:
    bool _binary_search(vector<vector<int>>& matrix,int low,int high,int target){
        
        if(low>high) return false;
        
        int mid= (low+high)/2;
        int m=matrix.size(), n=matrix[0].size();
        int row = mid/n, column = mid%n ;
        
        if(matrix[row][column]==target) return true;
        else if(target < matrix[row][column]) return _binary_search(matrix,low,mid-1,target);
        else return _binary_search(matrix,mid+1,high,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() * matrix[0].size();
        return _binary_search(matrix,0,n-1,target);
    }
};

// Time Compl: O(log(m*n)) Sapce: O(1)
