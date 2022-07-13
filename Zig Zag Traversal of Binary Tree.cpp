#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    if(root==NULL)
        return res;
    queue<BinaryTreeNode<int>*> Q;
    Q.push(root);
    int l_to_r = 0;
    while(!Q.empty())
    {
        l_to_r = 1 - l_to_r;
        int siz=Q.size();
        vector<int> v;
        for(int i=0; i<siz; i++)
        {
            BinaryTreeNode<int> *tmp=Q.front();
            Q.pop();
            v.push_back(tmp->data);
            if(tmp->left) 
                Q.push(tmp->left);
            if(tmp->right)
                Q.push(tmp->right);
        }
        if(l_to_r==0)
            reverse(v.begin(),v.end());
        res.insert(res.end(),v.begin(),v.end());
    }
    return res;
}
