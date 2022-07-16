TreeNode<int>* convert(vector<int> &arr,int lo,int hi)
{
    if(lo>hi)
        return NULL;
    int mid = (lo+hi)>>1;
    TreeNode<int> *curr = new TreeNode<int>(arr[mid]);
    curr->left = convert(arr,lo,mid-1);
    curr->right = convert(arr,mid+1,hi);
    return curr;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    TreeNode<int> *res = convert(arr,0,n-1);
    return res;    
}
// Time: O(n), Space: O(N)
