ListNode *segregateOnLastIndex(ListNode *head)
{
    ListNode* pivot=head;
    while(pivot->next!=NULL)
    {
        pivot=pivot->next;
    }
    
    ListNode* temp=head;
    ListNode* s=new ListNode(-1);
    ListNode* l=new ListNode(-1);
    ListNode *t1=s,*t2=l;
    while(temp!=NULL)
    {
        if(temp->val <= pivot->val)
        {
            t1->next=temp;
            t1=temp;
        }
        else
        {
            t2->next=temp;
            t2=temp;
        }
        temp=temp->next;
    }
    
    t2->next=NULL;
    t1->next=l->next;
    
    return pivot;
}