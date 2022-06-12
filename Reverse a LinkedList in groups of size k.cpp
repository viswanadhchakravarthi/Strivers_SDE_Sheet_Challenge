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

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
	Node* cur = head;
    Node* prevstart = NULL;
    if (!head)
        return head;
    for (int i=0;i<n;i++)
    {
        int size = b[i];
        if (size == 0)
            continue;
        if (size == 1)
        {
            if (prevstart)
                prevstart->next = cur;
            else
                head = cur;
            prevstart = cur;
            cur = cur->next;
            continue;
        }
        if (!cur)
            break;
        Node* prev = NULL;
        Node* start = cur;
        int ct = 0;
        while (cur && ct<size)
        {
            Node* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            ct++;
        }
        if (prevstart)
            prevstart->next = prev;
        else
            head = prev;
        prevstart = start;
    }
    if (cur)
    {
        if (prevstart)
            prevstart->next = cur;
        else
            head = cur;
    }
    return head;
}
