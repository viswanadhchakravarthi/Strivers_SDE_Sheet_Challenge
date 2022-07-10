/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<stack>
#include<vector>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res;
	if(root==NULL)
		return res;
	vector<int> In,Pre,Post;
	
	stack<pair<BinaryTreeNode<int> *,int>> st;
	st.push({root,1});
	while(!st.empty()){
		auto pr=st.top();
		st.pop();
		auto node=pr.first;
		int num=pr.second;
		// in PreOrder we need to traverse towards left side 
		// after visiting root
		if(num==1){
			Pre.push_back(node->data);
			num++;
			st.push({node,num});
			if(node->left)
				st.push({node->left,1});
		}
		// in InOrder we need to traverse towards right side
		// after visiting root
		else if(num==2){
			In.push_back(node->data);
			num++;
			st.push({node,num});
			if(node->right)
				st.push({node->right,1});
		}
		// no need to push anything again bcz in PostOrder
		// after visiting left & right it will come to root.
		else{
			Post.push_back(node->data);
		}
	}
	res.push_back(In);
	res.push_back(Pre);
	res.push_back(Post);
	return res;
}
