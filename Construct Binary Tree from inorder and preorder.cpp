#include<bits/stdc++.h>
TreeNode<int> *construct(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,unordered_map<int,int> &inMap)
{
    if(preStart>preEnd || inStart>inEnd)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int inRoot = inMap[root->data];
    int inLeft = inRoot-inStart;
    
    root->left = construct(preorder,preStart+1,preStart+inLeft,inorder,inStart,inRoot-1,inMap);
    root->right = construct(preorder,preStart+inLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
    
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int> inMap;
    for(int i=0; i<inorder.size(); i++)
        inMap[inorder[i]]=i;
    return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
}

// Time: O(N) , Space: O(N)
