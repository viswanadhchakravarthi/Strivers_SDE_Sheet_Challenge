class Iterative
{
  public:
    int floorInBST(TreeNode<int> * root, int x)
    {
        int floor = -1;
        while(root!=NULL)
        {
            if(root->val == x)
                return floor=x;
            if(x < root->val)
                root = root->left;
            else
            {
                floor = root->val;
                root = root->right;
            }
        }
        return floor;
    }
};
class Recursive
{
  public:
    void search(TreeNode<int> *root,int x,int &ans)
    {
        if(root==NULL)
            return;
        if(root->val>ans && root->val<=x)
            ans = root->val;
        if(x <= root->val)
            search(root->left,x,ans);
        else
            search(root->right,x,ans);
    }
    int floorInBST(TreeNode<int> * root, int X)
    {
        int ans = INT_MIN;
        search(root,X,ans);
        return ans;
    }
};
