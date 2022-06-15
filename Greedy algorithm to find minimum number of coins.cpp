int findMinimumCoins(int amount) 
{
	vector < int > ans;
      int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // these are always fixed
    int n = 9;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans.size();
}

/// Question in leetcode is the below

class Solution{
	public:
	// m is size of coins array (number of different coins)
	int minCoins(int coins[], int M, int V) 
	{
	    // table[i] will be storing the minimum number of coins
        // required for i value.  So table[V] will have result
	    int table[V+1];
	    
        // Base case (If given value V is 0)
	    table[0] = 0;
	    
	    // Initialize all table values as Infinite
	    for(int i=1; i<=V; i++) 
	        table[i]=INT_MAX;
	    
	    // Compute minimum coins required for all
        // values from 1 to V
	    for(int j=1; j<=V; j++)
	    {
	        // Go through all coins smaller than j
	        for(int k=0; k<M; k++)
	        {   
	            if(coins[k] <= j)
	            {
	                int sub_res = table[j-coins[k]];
	                if(sub_res != INT_MAX && sub_res+1 < table[j])
	                    table[j] = sub_res + 1; 
	            }
	        }
	    }
	    
	    if(table[V]==INT_MAX)
	        return -1;
	    
	    return table[V];
	} 
// 	Time: The time complexity of the above solution is O(mV).
// 	Space: O(V)
};
