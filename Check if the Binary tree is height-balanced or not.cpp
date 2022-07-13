int height(BinaryTreeNode<int> *root,int &ans)
{
    if(root==NULL)
        return 0;
    if(ans==0) // just to break recursion
        return 0;
    int l = height(root->left,ans);
    int r = height(root->right,ans);
    ans = ans & (((l-r)>=-1 and (l-r)<=1) ? 1 : 0);
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    int ans=1;
    height(root,ans);
    return ans;
}
