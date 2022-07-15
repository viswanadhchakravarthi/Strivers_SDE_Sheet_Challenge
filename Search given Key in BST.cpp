
bool searchInBST(BinaryTreeNode<int> *root, int x) { // not optimal
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    else if(x < root->data)
        return searchInBST(root->left,x);
    else
        return searchInBST(root->right,x);
 }
 // Time: O(height_of_tree) , Space : O(height)
 
 ----------------------- w/o space [ optimal ]
 

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root!=NULL && root->data != x )
          x < root->data ? root = root->left : root = root->right;
    return root==NULL ? false:true;
}
