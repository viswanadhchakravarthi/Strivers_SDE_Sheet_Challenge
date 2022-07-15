TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root==NULL)
        return NULL;
    int curr = root->data;
    if(P->data < curr && Q->data < curr)
        return LCAinaBST(root->left,P,Q);
    else if(P->data > curr && Q->data > curr)
        return LCAinaBST(root->right,P,Q);
    else
        return root;
}
// Time: O(H) ,Space: Can also be done with stack space as O(1)
