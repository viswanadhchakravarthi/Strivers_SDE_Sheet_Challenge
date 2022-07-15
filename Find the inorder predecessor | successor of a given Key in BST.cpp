class Solution1  // Completely Iterative
{
  public:
    pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
    {
        pair<int,int> ans={-1,-1};

        // finding successor
        BinaryTreeNode<int>* curr=root;
        while(curr!=NULL)
        {
            if(key >= curr->data)
                curr = curr->right;
            else
            {
                ans.second = curr->data; // store latest successor
                curr = curr->left;
            }
        }
        // finding predecessor
        curr = root;
        while(curr!=NULL)
        {
            if(key <= curr->data)
                curr = curr->left;
            else
            {
                ans.first = curr->data; // store latest predecessor
                curr = curr->right;
            }
        }
        return ans;
    }
};
class Solution2 // Recursive approach
{
  public:
    void check(BinaryTreeNode<int>* root, int key,pair<int,int>& ans)
    {
        if(root==NULL)
            return;
        if(root->data == key)
        {
            if(root->left)
            {
                BinaryTreeNode<int>* curr = root->left;
                while(curr->right!=NULL)
                    curr = curr -> right;
                ans.first = curr->data;
            }
            if(root->right)
            {
                BinaryTreeNode<int>* curr = root->right;
                while(curr->left!=NULL)
                    curr = curr -> left;
                ans.second = curr->data;
            }
            return;
        }
        if(key < root->data)
            check(root->left,key,ans);
        else
            check(root->right,key,ans);

        if(ans.first==-1 && root->data < key)
            ans.first = root->data;
        if(ans.second==-1 && root->data > key)
            ans.second = root->data;       
    }
    pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
    {
        pair<int,int> ans={-1,-1};
        check(root,key,ans);
        return ans;
    }
};
