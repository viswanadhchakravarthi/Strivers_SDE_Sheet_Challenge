void traverse(TreeNode<int> *root, int x, vector<int> &res){
    if(root==NULL) return;
    res.push_back(root->data);
    if(root->data == x)
        return;
    traverse(root->left,x,res);
    traverse(root->right,x,res);
    if(res.back()!=x)
        res.pop_back();
}
bool traverse(TreeNode<int> *root, int x, vector<int> &res){
    if(root==NULL) return false;
    res.push_back(root->data);
    if(root->data == x)
        return true;
    if(traverse(root->left,x,res)) return true;
    if(traverse(root->right,x,res)) return true;
    res.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;
    traverse(root,x,res);
    return res;
}
