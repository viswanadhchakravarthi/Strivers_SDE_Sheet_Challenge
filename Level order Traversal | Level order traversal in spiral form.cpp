vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> res;
    queue<BinaryTreeNode<int>*> Q;
    if(root)
        Q.push(root);
    while(!Q.empty())
    {
        int siz=Q.size();
        for(int i=0; i<siz; i++)
        {
            BinaryTreeNode<int> *tmp=Q.front();
            res.push_back(tmp->val);
            Q.pop();
            if(tmp->left)
                Q.push(tmp->left);
            if(tmp->right)
                Q.push(tmp->right);
        }
    }
    return res;
}

-------------------
