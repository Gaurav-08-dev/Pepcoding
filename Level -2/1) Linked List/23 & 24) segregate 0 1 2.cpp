/*************  Over Swapping Nodes **************/

ListNode *segregate012(ListNode *head)
{
    ListNode* h0= new ListNode(-1);
    ListNode* h1= new ListNode(-1);
    ListNode* h2= new ListNode(-1);
    
    ListNode* t0=h0,*t1=h1, *t2=h2;
    
    ListNode* temp=head;
    
    while(temp!=NULL)
    {
        if(temp->val==0)
        {
            t0->next=temp;
            t0=temp;
        }
        else if(temp->val==1){
            t1->next=temp;
            t1=temp;
        }
        else{
        t2->next=temp;
        t2=temp;
        }
        temp=temp->next;
    }
    
    
    // For safe side
    t2->next=NULL;
    
    
    t1->next=h2->next;
    t0->next=h1->next;
    
    return h0->next;
}



/*************  By Swapping Data -- changing reference**************/

ListNode *segregate012(ListNode *head)
{
    ListNode* i=head,*j=head,*k=head;
    while(i!=NULL)
    {
        if(i->val==0){
            swap(i->val,j->val);
            swap(j->val,k->val);
            i=i->next;
            j=j->next;
            k=k->next;
        }
        else if(i->val==1){
            swap(i->val,j->val);
            i=i->next;
            j=j->next;
        }
        else{
            i=i->next;
        }
    }
    return head;
}