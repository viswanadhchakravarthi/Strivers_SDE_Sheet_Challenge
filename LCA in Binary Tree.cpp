int findAncestor(TreeNode<int> * root,int x,int y)
{
    if(root==NULL)
        return -1;
    if(root->data==x || root->data==y)
        return root->data;
    int l = findAncestor(root->left,x,y);
    int r = findAncestor(root->right,x,y);
    if(l>=0 and r>=0)
        return root->data;
    if(l>=0)
        return l;
    return r;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return findAncestor(root,x,y);
}
