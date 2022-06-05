int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int maxi_on_right = prices[n-1];
    int profit_gained = 0;
    for(int i=n-2; i>=0; i--){
        if(maxi_on_right > prices[i])
            profit_gained = max( profit_gained, maxi_on_right-prices[i]);
        maxi_on_right = max( maxi_on_right, prices[i]);
    }
    return profit_gained;
}
// Time: O(n)
