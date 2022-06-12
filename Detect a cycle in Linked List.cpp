bool detectCycle(Node *head)
{
	if(head==NULL)  // here not check for head->nxt bcz at while loop anyhow we're checking 
            return false;
        
        Node *slow=head,*fast=head;
        
        while(fast->next && fast->next->next){ 
            // for 1st iteration, until now we've checked if head,head->nxt,head->nxt->nxt is NULL
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
                return true;
        }
        return false;
}

// time: O(n), space: O(1)




