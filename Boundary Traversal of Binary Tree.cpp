#include<bits/stdc++.h>
bool isLeaf(TreeNode<int>* root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    else
        return false;
}
void addLeftBoundary(TreeNode<int>* root,vector<int> &ans)
{
    root = root->left;
    while(root && isLeaf(root)==false)
    {
        ans.push_back(root->data);
        if(root->left)
            root=root->left;
        else
            root=root->right;
    }
}
void addLeafs(TreeNode<int>* root,vector<int> &ans)
{
    if(root==NULL)
        return;
    if(isLeaf(root))
        ans.push_back(root->data);
    addLeafs(root->left,ans);
    addLeafs(root->right,ans);
}
void addRightBoundary(TreeNode<int>* root,vector<int> &ans)
{
    root = root->right;
    vector<int> temp;
    while(root && isLeaf(root)==false)
    {
        temp.push_back(root->data);
        if(root->right)
            root=root->right;
        else
            root=root->left;
    }
    reverse(temp.begin(),temp.end());
    ans.insert(ans.end(),temp.begin(),temp.end());
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root)
        return ans;
    if(!isLeaf(root))
        ans.push_back(root->data);
    addLeftBoundary(root,ans); // w/o leafs
    addLeafs(root,ans);         // add only leafs from left to right
    addRightBoundary(root,ans); // w/o leafs
    return ans;
}
