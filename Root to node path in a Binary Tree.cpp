bool getPath(TreeNode* root,int node,vector<int> &res)
{
    if(root==NULL)
        return false;
    res.push_back(root->val);
    if(root->val == node)
        return true;
    if( getPath(root->left,node,res) || getPath(root->right,node,res) )
        return true;
    res.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    getPath(A,B,res);
    return res;
}
