#include<bits/stdc++.h>
TreeNode<int> *construct(vector<int>& postOrder,int postStart,int postEnd,vector<int> inOrder,int inStart,int inEnd,unordered_map<int,int>& inMap)
{
    if(postStart>postEnd || inStart>inEnd)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(postOrder[postEnd]);
    int inRoot = inMap[root->data];
    int inRight = inEnd - inRoot;
    
    root->right = construct(postOrder,postEnd-inRight,postEnd-1,inOrder,inRoot+1,inEnd,inMap);
    root->left  = construct(postOrder,postStart,postEnd-inRight-1,inOrder,inStart,inRoot-1,inMap);
    
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	unordered_map<int,int> inMap;
    for(int i=0; i<inOrder.size(); i++)
        inMap[inOrder[i]] = i;
    return construct(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,inMap);
}

// Time: O(N) , Space: O(N)
