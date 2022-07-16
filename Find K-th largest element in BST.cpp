void reverseInOrder(TreeNode<int>* root,int &k,int &ans)
{
    if(!root) return;
    reverseInOrder(root->right,k,ans);
    k--;
    if(k==0)
    {
        ans = root->data;
        return;
    }
    reverseInOrder(root->left,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    reverseInOrder(root,k,ans);
    return ans;
}
