/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> res;
        if(root==NULL)
            return res;
        //map<int,map<int,multiset<int>>> nodes; //in LeetCode asked for sorted, if same position
        map<int,map<int,vector<int>>> nodes;  // but in CodeStudio asked for left-to-right, if same position
        queue<pair<TreeNode<int>*,pair<int,int>>> q;
    
        q.push({root,{0,0}});
        while(!q.empty()){
            auto pr=q.front();
            q.pop();
            TreeNode<int>* node=pr.first;
            int line=pr.second.first;
            int level=pr.second.second;
            //nodes[line][level].insert(node->data); // LeetCode
            nodes[line][level].push_back(node->data); // CodeStudio
            
            if(node->left)
                q.push({node->left,{line-1,level+1}});
            if(node->right)
                q.push({node->right,{line+1,level+1}});
        }
        for(auto it1: nodes){ // traversing over map<int,map<int,multiset<int>>>
            //vector<int> tmp;
            for(auto it2:(it1.second)) // traversing over map<int,multiset<int>>
            { 
                // inserting all elements of multiset<int> which are defaultly sorted, at end of tmp
                res.insert(res.end(),it2.second.begin(),it2.second.end());
                //tmp.insert(tmp.end(),it2.second.begin(),it2.second.end()); 
            }
            //res.push_back(tmp);
        }
        return res;
}
