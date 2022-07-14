class Recursive // Time: O(N) & Space: O(N)
{
  void flatten(TreeNode<int> *root,TreeNode<int>* &prev)
  {
      if(root==NULL)
          return;
      flatten(root->right,prev);
      flatten(root->left,prev);
      root -> right = prev;
      root -> left = NULL;
      prev = root;
  }
  TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
  {
      TreeNode<int>* prev=NULL;
      flatten(root,prev);
      return prev;
  }
};
