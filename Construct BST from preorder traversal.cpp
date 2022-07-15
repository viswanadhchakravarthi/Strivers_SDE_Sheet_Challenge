#include<bits/stdc++.h>
TreeNode<int> *construct(vector<int>& preOrder,int &ind,int upper_b)
{
    if(ind==preOrder.size() || preOrder[ind]>=upper_b)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preOrder[ind++]);
    
    root->left = construct(preOrder,ind,root->data);
    root->right = construct(preOrder,ind,upper_b);
    
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){ // Construct BST from preorder traversal
    int ind=0;
    return construct(preOrder,ind,INT_MAX);
}

// time: O(N)
