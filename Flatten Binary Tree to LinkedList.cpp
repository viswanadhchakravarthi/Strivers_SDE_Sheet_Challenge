class using_morris_traversal // time: O(N) , Space: O(1) ==> most optimal solution
{
  public:
      TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
      {
          TreeNode<int> *curr = root;
          while(curr)
          {
              if(curr->left)
              {
                  TreeNode<int> *prev = curr->left;
                  while(prev->right)
                      prev = prev->right;
                  prev->right = curr->right;
                  curr ->right = curr->left;
              }
              curr = curr->right;
          }
          return root;
      }
};

class Recursive // Time: O(N) & Space: O(N)
{
  public:
      void flatten(TreeNode<int> *root,TreeNode<int>* &prev)
      {
          if(root==NULL)
              return;
          flatten(root->right,prev);
          flatten(root->left,prev);
          root -> right = prev;
          root -> left = NULL;
          prev = root;
      }
      TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
      {
          TreeNode<int>* prev=NULL;
          flatten(root,prev);
          return prev;
      }
};

// Recursive & Iterative appraoches are quite different

class Iterative // Time: O(N) , Space: O(N)
{
  public:
    TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
    {
        stack<TreeNode<int>*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode<int> *curr = st.top();
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            if(!st.empty())
                curr -> right = st.top();
            curr -> left = NULL;
        }
        return root;
    }
};
