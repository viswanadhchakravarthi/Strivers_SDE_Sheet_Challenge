class Solution_Recursive {
public:
    // ab+
    void postorder(TreeNode* root,vector<int> &res){
        if(root==NULL)
            return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};
// Time: O(#nodes) , Space: O(H)

class Solution_Iterative {
public:
    // ab+ = reverse(+ba)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            res.push_back(root->val);
            if(root->left)
                st.push(root->left);
            if(root->right)
                st.push(root->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// Time: O(n) , Space : O(n+n) bcz we need Auxilary space to reverse the o/p we got, for that we can also use Stack( just to reverse the elements ).
