#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
// Brute Force is of O(n) time & O(n) for map
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head==NULL)
           return head;
    LinkedListNode<int> *h_tmp=head;
    LinkedListNode<int> *clone=new LinkedListNode<int>(0);
    LinkedListNode<int> *c_tmp=clone;

    // step1: make deep copies of nodes
    while(h_tmp!=NULL){
        LinkedListNode<int> *cnode=new LinkedListNode<int>(h_tmp->data);
        cnode->next=h_tmp->next;
        h_tmp->next=cnode;
        h_tmp=cnode->next;
    }
    // step2: initialise Random ptrs
    h_tmp=head;
    while(h_tmp!=NULL){
        if(h_tmp->random==NULL)
            h_tmp->next->random=NULL;
        else
            h_tmp->next->random = h_tmp->random->next;
        h_tmp=h_tmp->next->next;
    }
    // step3: rearrange nxt ptrs
    clone->next=head->next;
    h_tmp=head;
    while(h_tmp!=NULL){
        c_tmp = c_tmp->next = h_tmp->next;
        h_tmp = h_tmp->next = c_tmp->next;
    }
    return clone->next;
}
// Time: O(n), Space: O(1)
