/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

// we can do using Reverse Level order: time= O(#nodes) & space= O(#nodes)[for queue] + O(#nodes)[for stack]
// But we can solve using Level order: time= O(#nodes) & space= O(#nodes)[for queue]. ----> ( w/o stack )
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;
    if(root==NULL)
        return res;

    map<int,int> mpp;
    queue<pair<TreeNode<int>*,int>> q; //node,index

    q.push({root,0});
    while(!q.empty()){
        pair<TreeNode<int>*,int> pr=q.front();
        q.pop();

        TreeNode<int> *curr=pr.first;
        int index=pr.second;

        if(mpp.find(index)==mpp.end())
            mpp[index]=curr->val;

        if(curr->left)
            q.push({curr->left,index-1});
        if(curr->right)
            q.push({curr->right,index+1});
    }

    for(auto i:mpp)
        res.push_back(i.second);
    return res;
}
