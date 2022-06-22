#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int m, int n, int k) {

    if(n<m)
        return ninjaAndLadoos(b,a,n,m,k);
    int low = max(0,k-n), high = min(m,k); // didn't understand y low is take like this
    while(low <= high)
    {
        int cut1 = (low + high)>>1; // never -ve bcz we r considering smaller array here
        int cut2 = k - cut1;
        int l1 = cut1==0 ? INT_MIN : a[cut1-1];
        int l2 = cut2==0 ? INT_MIN : b[cut2-1];
        int r1 = cut1==m ? INT_MAX : a[cut1];
        int r2 = cut2==n ? INT_MAX : b[cut2];
        
        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2);
        }
        else if(l1>r2)
        {
            high = cut1 - 1;
        }
        else
            low = cut1 + 1;
    }
    return -1;
}
// time: O( log ( min(m,n ))
