class Solution {
public:
    // root , left , right
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};
// Time: O(n) , Space: O(1)
// Most efficient solution for Preorder/Inorder/Postorder with minor changes
// For Post-order we need to think in Reverse Order......
