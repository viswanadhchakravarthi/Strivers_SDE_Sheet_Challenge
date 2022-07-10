class Solution_Recursive {
public:
    // +ab
    void preorder(TreeNode* root,vector<int> &res){
        if(root==NULL) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};
// Time: O(#nodes) , Space: O(H)

class Solution_Iterative {
public:
    // +ab
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            res.push_back(root->val);
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
        }
        return res;
    }
};
// time: O(#nodes) , space: O(H)
