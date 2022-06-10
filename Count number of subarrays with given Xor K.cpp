#include<bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
	map<int,int> mp;
    int xorr=0;
    int count=0;
    for(int i=0 ; i<arr.size() ; i++) // O(n)
    {
    	xorr = xorr ^ arr[i];
		if( xorr == x ) 
			count++;
		int y = xorr ^ x;
		if(mp.find(y)!=mp.end()) // O(log(n))
        	count += mp[y];
        mp[xorr]++;	// O(logn)
    }
 	return count;
}
// time Complexity : O(n logn), Space Complexity: O(n)

// xorr =1 , count =3 , i =4 , x=6 , y=7

// mp = {(4,2), (2,1), (1,1)}
// 4 2 2 6 3

// 4 ^ 2 = 6
// 2 ^ 2 ^ 6 = 6
// 6 
	
// ans: 3
