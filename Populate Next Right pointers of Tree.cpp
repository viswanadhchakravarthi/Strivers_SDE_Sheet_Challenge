#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    if(root==NULL)
        return;
    queue<BinaryTreeNode< int >*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        int size = Q.size();
        for(int i=0; i<size; i++)
        {
            BinaryTreeNode< int > *curr = Q.front();
            Q.pop();  
            if(i!=size-1)
            {
                curr->next = Q.front();
            }
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
        }
    }
}
// Time: O(N) , Space: O(N)
