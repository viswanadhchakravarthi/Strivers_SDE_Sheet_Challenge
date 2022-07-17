/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
class BSTiterator
{
    private:
    bool is_forw_itr;
    stack<BinaryTreeNode<int>*> myStack;
    void pushAll(BinaryTreeNode<int> *node)
    {
        while(node!=NULL)
            myStack.push(node), node = is_forw_itr? node->left : node->right;
    }
    public:
    BSTiterator(BinaryTreeNode<int> *root,bool c)
    {
        is_forw_itr = c;
        pushAll(root);
    }
    int next()
    {
        BinaryTreeNode<int> *tmpNode = myStack.top();
        myStack.pop();
        is_forw_itr? pushAll(tmpNode->right) : pushAll(tmpNode->left);
        return tmpNode->data;
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTiterator l(root,true); // Forward iterator
    BSTiterator r(root,false); // Backward iterator
    int i = l.next(), j = r.next();
    while(i<j)
    {
        if(i+j == k)
            return true;
        else if(i+j > k)
            j = r.next();
        else
            i = l.next();
    }
    return false;
}

// Time: O(N) , space: O(2*H)
