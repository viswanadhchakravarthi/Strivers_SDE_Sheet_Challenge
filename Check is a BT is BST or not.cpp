bool isBST(BinaryTreeNode<int> *root,int l,int r)
{
    if(root==NULL)
        return true;
    if(root->data < l || root->data > r)
        return false;
    return isBST(root->left,l,root->data) && isBST(root->right,root->data,r);
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,INT_MIN,INT_MAX);
}
// Time: O(N)
