#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> ps(n),ns(n),ans(n,INT_MIN);
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && a[i]<=a[s.top()]) 
            s.pop();
        ps[i] = s.empty()? -1:s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && a[i]<=a[s.top()]) 
            s.pop();
        ns[i] = s.empty()? n:s.top();
        s.push(i);
    }
    vector<int> ind_diff(n);
    for(int i=0; i<n; i++)
        ind_diff[i] = ns[i] - ps[i] - 2; //  two times -1 + -1
    for(int i=0; i<n; i++)
        ans[ind_diff[i]] = max(a[i],ans[ind_diff[i]]);
    for(int i=n-2; i>=0; i--)
        ans[i] = max(ans[i],ans[i+1]);
    return ans;
}
// Time: O(n) , Space: O(n)
