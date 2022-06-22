#include<bits/stdc++.h>

// Median of 2 sorted arrays
// Time: O(min(log n1, logn n2))
double median(vector<int> a, vector<int> b)
{
    int n1 = a.size(), n2 = b.size();
    if(n2<n1)
        return median(b,a);
    int low = 0, high = n1;
    while(low <= high)
    {
        int cut1 = (low+high) >> 1; // never -ve bcz we r considering smaller array here
        int cut2 = (n1+n2+1)/2 - cut1;
        int l1 = cut1==0 ? INT_MIN : a[cut1-1];
        int l2 = cut2==0 ? INT_MIN : b[cut2-1];
        int r1 = cut1==n1 ? INT_MAX : a[cut1];
        int r2 = cut2==n2 ? INT_MAX : b[cut2];
        
        if(l1<r2 && l2<r1)
        {
            if((n1+n2)%2==0)
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            else
                return max(l1,l2);
        }
        else if(l1>r2)
        {
            high = cut1 - 1;
        }
        else
            low = cut1 + 1;
    }
    return 0.0;
}

