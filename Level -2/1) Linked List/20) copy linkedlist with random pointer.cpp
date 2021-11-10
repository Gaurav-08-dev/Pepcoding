/*************** USING HASHMAP ******************/

ListNode *copyRandomList(ListNode *head)
{
    if(head == NULL) return NULL;

    /*** Make a copy of linkedlist with next pointer only ***/

    ListNode* head2= head;

    map<ListNode*,ListNode*> m;

    while(head2)
    {
    	m[head2]=new ListNode(head2->val);
    	head2=head2->next;
    }

    head2=head;

    while(head2)
    {
    	m[head2]->next=m[head2->next];
    	m[head2]->random=m[head2->random] ;
    	head2=head2->next;   
    }

    return m[head];

}