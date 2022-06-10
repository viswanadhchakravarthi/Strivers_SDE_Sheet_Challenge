Node *findMiddle(Node *head) {
    if(head == NULL | head->next == NULL) return head;
        
        Node *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}
// Time comp: O(n/2) bcz fast ptr moved to end in n/2 iterations, Space comp: O(1)

// Dry run:
// NULL (ans:NULL)
// 1->  (ans:1)
// 1->2-> (ans:2)

// 1->2->3->4->5->NULL
// 1k 2k 3k 4k 5k
// slow=3k
// fast=5k
