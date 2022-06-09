int uniquePaths(int m, int n) {
	int N = m+n-2;
        int r = m-1; // r can also be n-1, anyhow result will be same 
        
        if(r > N-r) r = N-r; // Optional
        // try to make some observations ans is Combination( m-1 + n-1 , n-1 or m-1 )
        double result=1;
        for(int i=1 ; i<=r ; i++)
            result = result* (N-r+i) / i;
        //  result = result* (N-i+1) / i; // the only diff with below one is multiplication of numerator is done from smaller end. 
        return result;
}
// Time Complexity : O(m-1) or O(n-1)
// This approach uses combinatorics --> optimised one
