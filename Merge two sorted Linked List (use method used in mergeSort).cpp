Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        // here ( list1==NULL && list2==NULL ) case is implicit in above condition
        
        if(list1->data > list2->data) swap(list1,list2); 
        // always l1 has smaller element
        
        Node<int>* res=list1;
        
        while(list1!=NULL && list2!=NULL){
            Node<int>* tmp=NULL;
            // below, loop is bcz of duplicates/continuos smaller element than other list 
            while(list1!=NULL && list1->data <= list2->data)  tmp=list1, list1=list1->next;
            tmp->next=list2; // use Dry run for more clarity in this step
            swap(list1,list2); // use Dry run for more clarity in this step
        }
        return res;
}
// Time : O(len(list1)+len(list2)) , Space: O(1)
