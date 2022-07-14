bool symmetricTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
        if(root1==NULL and root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        return root1->data==root2->data && symmetricTrees(root1->left,root2->right) && symmetricTrees(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
        if(root==NULL)
            return true;
        return symmetricTrees(root->left,root->right);
}
