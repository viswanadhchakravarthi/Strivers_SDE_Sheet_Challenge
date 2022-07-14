#include<bits/stdc++.h>
class CodeStudio
{
  public:
  int path(TreeNode<int> *root, int &ans,int &nof_leafs)
  {
      if(root==NULL)
          return 0;
      if(root->left ==NULL && root->right==NULL)
          nof_leafs += 1;
      int l = path(root->left,ans,nof_leafs); 
      int r = path(root->right,ans,nof_leafs);
      ans = max(ans, l+r+root->val);
      return root->val + max(l,r);
  }
  long long int findMaxSumPath_between_leaves(TreeNode<int> *root)
  {
      int ans = INT_MIN;
      int nof_leafs=0;
      path(root,ans,nof_leafs);
      if(nof_leafs<=1)
          return -1;
      return ans;
  }
};
class LeetCode
{
  public:
  int path(TreeNode<int> *root, int &ans)
{
    if(root==NULL)
        return 0;
    // for below CodeStudio code fails
//         12
//        /  \
//       3    10
//           /  \
//          -5   -7
    // if question is path not asked for only b/w leaves then below add l = max(0,1) & r = max(0,r)
    int l = max(0,path(root->left,ans)); 
    int r = max(0,path(root->right,ans));
    ans = max(ans, l+r+root->val);
    return root->val + max(l,r);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    int ans = INT_MIN;
    path(root,ans);
    return ans;
}
};
