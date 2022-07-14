void changeTree(BinaryTreeNode < int > * root) { // Time: O(N) , Space:O(N)
    if(root==NULL)
        return;
    int sum=0;
    if(root->left) 
      sum += root->left->data;
    if(root->right) 
      sum +=  root->right->data;
    if(sum < root->data)
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    else{ // Anyhow when we backTrack summation of child's data is stored in curr->val. So, this part can be ignored
        root->data = sum;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) // make sure there is some child below the root, or else it would end up making curr node data as zero
        root->data = total;
}  
