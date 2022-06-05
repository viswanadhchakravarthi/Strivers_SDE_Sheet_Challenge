vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // next_permutation(permutation.begin(),permutation.end()); //--> in-built 
    int i=permutation.size()-2;
    while( i>=0 && permutation[i]>=permutation[i+1]) i--;
        
        if(i >= 0){
            int j=permutation.size()-1;
            while(permutation[i] >= permutation[j]) 
                j--;
            swap(permutation[i],permutation[j]); // in-built 
        }
        reverse(permutation.begin()+i+1,permutation.end());
    return permutation;
}

// Time : O(n) ,Space : O(1)

// intuition behind this algorithm is just note down some observations
// how one permutation is getting changed to next-one.
