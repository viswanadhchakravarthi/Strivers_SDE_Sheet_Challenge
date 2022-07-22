#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
   if(root==NULL)
       return "";
    queue<TreeNode<int>*> q;
    string s = "";
    q.push(root);
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        if(curr==NULL)    s.append("#,");
        else{
            s.append(to_string(curr->data)+',');
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
   if(serialized.size()==0)
       return NULL;
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str=="#")    curr->left = NULL;
        else        q.push(curr->left = new TreeNode<int>(stoi(str)));
        
        getline(s,str,',');
        if(str=="#")    curr->right = NULL;
        else        q.push(curr->right = new TreeNode<int>(stoi(str)));
    }
    return root;
}

// Time: O(N) , Space: O(N)
