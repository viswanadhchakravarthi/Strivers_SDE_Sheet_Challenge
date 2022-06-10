LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    LinkedListNode<int> *start = new LinkedListNode<int>(0); // **Intuition**
    start->next=head;
    LinkedListNode<int> *slow=start,*fast=start;
     if(head==NULL || K==0)
       return head;
    for(int i=1; i<=K ; i++) 
        fast=fast->next;
    while(fast->next != NULL) {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next; // we are able to do this w/o any doubt bcz #nodes>=2 bcz of dummy node
    return start->next; //bcz start is not the head, its a dummy before head
}
// time: O(n) -> one pass , Space :O(1)
