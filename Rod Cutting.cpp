int cutRod(vector<int>& price,int N) {
    vector<int> prev(N+1,0);
    for(int i=0; i<=N; i++){
        prev[i] = i*price[0];
    }
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
             int notTaken = 0 + prev[length];
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + prev[length-rodLength];
             prev[length] = max(notTaken,taken);   
        }
    }
    return prev[N];
}
