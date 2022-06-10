Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy,*dummy_last;
    dummy_last = dummy = new Node(0); // remember dummy->nxt should be returned.

    int carry=0;
    while(head1 || head2 || carry){
        int sum = 0;
        if(head1) sum += head1->data, head1 = head1->next;
        if(head2) sum += head2->data, head2 = head2->next;
        sum += carry;
        carry = sum / 10;
        Node *tmp = new Node(sum % 10);
        dummy_last = dummy_last->next = tmp;
    }
    return dummy->next; 
}
// Time : O(m+n)
// probably we have only one solution which is optimal with diffn implementations which might reduce #lines.
