class NodeValue
{
    public:
    int minNode,maxNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSThelper(TreeNode<int>* root)
{
    if(root==NULL)
        return NodeValue(INT_MAX,INT_MIN,0);
    auto left = largestBSThelper(root->left);
    auto right = largestBSThelper(root->right);
    if(root->data > left.maxNode && root->data < right.minNode)
    {// this is BST
        return NodeValue( min(left.minNode,root->data), max(right.maxNode,root->data), left.maxSize + right.maxSize + 1);
    }
    else
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    return largestBSThelper(root).maxSize;
}
// Time: O(N) , Space: O(H)
