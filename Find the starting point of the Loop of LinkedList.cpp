#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	if(head==NULL)  // here not check for head->nxt bcz at while loop anyhow we're checking 
            return head;
        
        Node *slow=head,*fast=head,*entry=head;
        
        while(fast->next && fast->next->next){ 
            // for 1st iteration, until now we've checked if head,head->nxt,head->nxt->nxt is NULL
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
}
// Time Complexity: O(N)
// Reason: We can take overall iterations club it to O(N)

// Space Complexity: O(1)
// Reason: No extra data structure is used.
