#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> nse(n,-1);
    stack<int> s;
    
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && s.top()>=arr[i])
            s.pop();
        if(!s.empty())
            nse[i]=s.top();
        else
            nse[i]=-1;
        s.push(arr[i]);
    }
    return nse;
}
