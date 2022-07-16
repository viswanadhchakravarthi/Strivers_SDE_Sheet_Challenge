void inOrder(TreeNode<int> *root,int &k,int &ans)
{
    if(!root) return;
    inOrder(root->left,k,ans);
    k--;
    if(k==0)
    {
      ans = root->data;
      return;
    }
    inOrder(root->right,k,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans=-1;
    inOrder(root,k,ans);
    return ans;
}

// Time: O(N) , Space: O(N) space can be avoided using morris inoder traversal
