int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil = -1;
    while(root!=NULL)
    {
        if(root->data==x)
            return ceil=x;
        if(root->data < x)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
// Time: O(H)
