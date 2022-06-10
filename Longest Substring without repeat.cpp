#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
        vector<int> h_t(256,-1);
        int left=0, right=0, len=0, n=s.size();
        while(right<s.size()){
            if( h_t[s[right]] != -1 )  
                left = max( h_t[s[right]]+1, left);
            h_t[s[right]] = right;
            len = max( len, right-left+1 );
            right++;
        }
        return len;
}

// Time Complexity: O(n+n) --> better than other approach bcz we'r directly jumping to right from left ptr, space complexity: O(1)

// 012345678
// pwbkewabc
// ans : 6
// i=3 , j=9 , length=6
// {kewabc}

// 1. check for charac
// 2. if found , move nxt NA place
// 3. store in hash-table

// bbbb --> worst case getting O(2n) time complexity
