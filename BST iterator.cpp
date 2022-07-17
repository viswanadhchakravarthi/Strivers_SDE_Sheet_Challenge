/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

/*
Naive solution is store inorder then Time: O(1) for next and hasNext but Space: O(N) to all node elements

Optimal solution(below) : time complexity [ next/hasNext ] : O(N/N) = O(1) on average & space: O(H)
*/

class BSTiterator
{
    private:
    stack<TreeNode<int>*> myStack;
    void pushAll(TreeNode<int> *node)
    {
        while(node!=NULL)
            myStack.push(node), node = node->left;
    }
    public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
