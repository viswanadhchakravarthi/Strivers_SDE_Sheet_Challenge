class Solution_Recursive {
public:
    // left , root, right
    void inorder(TreeNode* root,vector<int> &res){
        if(root==NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
// Time : O(n), Space: O(n) in skewed trees

class Solution_Iterative {
public:
    // left , root, right
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(true){
            if(root!=NULL) 
            st.push(root),root=root->left;
            else{
                if(st.empty())
                    break;
                root=st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        
        return res;
    }
};
// Time: O(n), space:O(H)
