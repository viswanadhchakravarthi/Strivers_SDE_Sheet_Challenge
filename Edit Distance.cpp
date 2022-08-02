int editDistance(string str1, string str2)
{
    // Modify s1, to make it as s2
    int n=str1.size(), m=str2.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    // 1 based indexing , to make tabulation easier
    // base cases:
    for(int j=0; j<=m; j++) prev[j] = j; // i==0 : put j 
    
    for(int i=1; i<=n; i++){
        // base case:
        cur[0] = i; // j==0 : put i
        for(int j=1; j<=m; j++){
            // match:
            if(str1[i-1]==str2[j-1]) cur[j] = prev[j-1];
    
            // no match: 1 + min(dele,min(repl,ins))
            else cur[j] = 1 + min(prev[j],min(prev[j-1],cur[j-1]));
        }
        prev = cur;
    }
    return prev[m];
}

// time: O(n*m) , Space: O(m)
