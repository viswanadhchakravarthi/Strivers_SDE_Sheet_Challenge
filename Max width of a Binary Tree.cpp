int getMaxWidth(TreeNode<int> *root) // #nodes in a level -> simple
{
    int ans=0;
    
    queue<TreeNode<int>*> Q;
    if(root)
        Q.push(root);
    while(!Q.empty())
    {
        int siz=Q.size();
        ans = max(ans,siz);
        for(int i=0; i<siz; i++)
        {
            TreeNode<int> *tmp=Q.front();
            Q.pop();
            if(tmp->left)
                Q.push(tmp->left);
            if(tmp->right)
                Q.push(tmp->right);
        }
    }
    return ans;
}

------------------------------

int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        long long width = 0;
        queue<pair<TreeNode*,long long>> q; // node,index-starting-from-zero-within-a-level
        q.push({root,0});
        while(!q.empty())
        {
            long long size = q.size();
            long long start_ind = q.front().second;
            long long curr_ind;
            for(long long i=0;i<size;i++)
            {
                TreeNode* node = q.front().first;
                curr_ind = q.front().second-start_ind;
                q.pop();
                if(node->left)
                    q.push({node->left,curr_ind*2+1});
                if(node->right)
                    q.push({node->right,curr_ind*2+2});
            }
            width = max(width,curr_ind+1); // bcz curr_ind itself is the width but starting with 0
        }
        return (int)width;
    }
    // Time: O(n)
    // Space: O(n)
