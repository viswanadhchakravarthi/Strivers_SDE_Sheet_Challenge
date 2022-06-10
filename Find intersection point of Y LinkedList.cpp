// Optimal Solution
int findIntersection(Node *headA, Node *headB)
{
    if( headA==NULL || headB==NULL)  return -1;
    
    Node *a=headA,*b=headB;
    // if a & b have different length, then we will stop the loop after 2nd iteration
    while(a!=b){
        // for the end of 1st iteration, we just reset the pointer to the head of another LinkedList
        a = (a==NULL) ? headB : a->next;
        b = (b==NULL) ? headA : b->next; 
    }
    if(a==NULL)
        return -1;
    return a->data;
}
