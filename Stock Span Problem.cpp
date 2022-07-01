#include<stack>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int> res(n);
    vector<pair<int,int>> nge(n,{-1,-1});
    stack<pair<int,int>> s;
    
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && (s.top()).first <= price[i])
            s.pop();
        if(!s.empty())
            nge[i]=s.top();
        else
            nge[i]={-1,-1};
        s.push({price[i],i});
    }
    for(int i=0; i<n; i++)
    {
        res[i] =  i - nge[i].second;
    }
    return res;
}
// Same as Next Greater than element , but do the same from right to left of given array
