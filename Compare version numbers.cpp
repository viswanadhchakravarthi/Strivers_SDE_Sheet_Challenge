#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    int i=0, j=0, m=a.size(), n=b.size();
    while(i<m or j<n){
        long x=0, y=0;
        while(i<m and a[i]!='.'){
            x = x*10 + (a[i]-'0');
            i++;
        }
        while(j<n and b[j]!='.'){
            y = y*10 + (b[j]-'0');
            j++;
        }
        if(x>y)
            return 1;
        if(x<y)
            return -1;
        i++;
        j++;
    }
    return 0;
}
