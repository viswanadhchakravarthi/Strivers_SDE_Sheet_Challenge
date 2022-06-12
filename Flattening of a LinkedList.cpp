#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *mergeLists(Node* A,Node* B)
{
    Node* tmp = new Node(0);
    Node *merger_head=tmp;
    while(A!=NULL && B!=NULL){
        if(A->data <= B->data){
            tmp->child=A;
            tmp=A;
            A=A->child;
        }
        else{
            tmp->child=B;
            tmp=B;
            B=B->child;
        }
    }
    if(A!=NULL) tmp->child=A;
    if(B!=NULL) tmp->child=B;
    merger_head->child->next=NULL; // added than LeetCode
    return merger_head->child;
}

/*  Function which returns the  root of the flattened linked list. */

Node *flattenLinkedList(Node *root)
{
   if(root==NULL)
            return root;
   if(root->next==NULL)
            return root;  
   Node *res=flattenLinkedList(root->next);
   return mergeLists(root,res);
}

// Time Complexity: O(N), where N is the total number of nodes present

// Reason: We are visiting all the nodes present in the given list.

// Space Complexity: O(1), w/o recursion stack which is O(n)n in worst case

// Reason: We are not creating new nodes or using any other data structure.
