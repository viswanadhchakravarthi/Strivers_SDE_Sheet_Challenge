LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // if(head == NULL || head->next==NULL) return head; --> not required,code will handle
        
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
// Time comp: O(n)[single traversal] Space comp: O(1)

// Dry run:
//             NULL<-1<-2<-3<-4<-5  NULL
// nxt_ptr:                          nx             
// head:                             h             
// dummy:                        d  
