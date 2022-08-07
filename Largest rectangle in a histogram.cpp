class better{
public:

int largestRectangle(vector < int > & heights) {
    stack<int> st;
    int n = heights.size();
    vector<int> leftSmall(n),rightSmall(n);
    
    for(int i=0; i<n; i++){
        while(!st.empty() and heights[i]<=heights[st.top()]) 
            st.pop();
        if(st.empty()) leftSmall[i] = 0; 
        else           leftSmall[i] = st.top()+1;
        st.push(i);
    }
    
    while(!st.empty()) st.pop(); // clear everything 
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() and heights[i]<=heights[st.top()]) 
            st.pop();
        if(st.empty()) rightSmall[i] = n-1;
        else           rightSmall[i] = st.top()-1;
        st.push(i);
    }
    
    int res = 0;
    for(int i=0; i<n; i++){
        res = max( res, (rightSmall[i]-leftSmall[i]+1)*heights[i] );
    }
    return res;
}
// time: O(n for leftSmall + n for rightSmall)
// space: O(2n for left n right + n for stack)
// still it can be reduced to 1 parse solution
};

class optimal{
public:

int largestRectangle(vector < int > & heights) {
    stack<int> st;
    int n = heights.size();
    
    int res = 0;
    for(int i=0; i<=n; i++){ // should go till n
        while(!st.empty() and (i==n or heights[st.top()]>=heights[i]) ){
            int ind = st.top();
            st.pop();
            
            int width;
            if(st.empty()) width = i;
            else           width = i - st.top() - 1;
            
            res = max( res, width*heights[ind]);
        }
        st.push(i);
    }
    return res;
}
// one parse solution 
// time: O(n)
// space: O(n)
};
