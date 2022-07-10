class Solution {
public:
    // left , root, right
    // Inorder using morris Traversal( using Threaded Binary Tree concept )
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};
// Time: O(n) , Important thing to be noted is Space: O(1)😳 for inorder Traversal

// Approach:
// In-order Morris Traversal:
// 🌳 1st case: if left is null, print current node and go right
// 🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
// 🌳 3rd case: if thread is already pointed to current node, then remove the thread
