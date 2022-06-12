#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> * reverseList(LinkedListNode<int> * head) {
        LinkedListNode<int> *newHead=NULL,*nxt;
        while(head!=NULL){
            // saving next node for reference
            nxt=head->next;
            // breaking old link, and adding a new link
            head->next=newHead;
            // shift all ptr's to repeat the above steps
            newHead=head;
            head=nxt;
        }
        return newHead; // bcz dummy pointing to last element
    }
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL)
            return true;
        LinkedListNode<int> *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        
        LinkedListNode<int> *tmp=head;
        slow=slow->next;
        while(slow!=NULL){
            if(slow->data != tmp->data) 
                return false;
            slow=slow->next;
            tmp=tmp->next;
        }
        return true;
}
// O(1) extra space, Time Complexity: O(N/2)+O(N/2)+O(N/2)
