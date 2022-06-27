#include<stack>
vector<int> nextGreater_on_right(vector<int> &arr, int n) {

    vector<int> nge(n,-1);
    stack<int> s;
    
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
        if(!s.empty())
            nge[i]=s.top();
        else
            nge[i]=-1;
        s.push(arr[i]);
    }
    return nge;
}

vector<int> nextGreater_on_right_in_circular_fashion(vector<int> &arr, int n) {

    vector<int> nge(n,-1);
    stack<int> s;
    
    for(int i=2n-1; i>=0; i--) 
    {
        while(!s.empty() && s.top()<=arr[i%n])
            s.pop();
        if(i<n)
        {
          if(!s.empty())
            nge[i]=s.top();
          else
            nge[i]=-1;
        }
        s.push(arr[i%n]);
    }
    return nge;
}
// we can want to check in circular, so we just assume as if we are copying same arr, nxt to curr arr
// [ 1 2 3 4 ] + [ 1 2 3 4 ] , like this
