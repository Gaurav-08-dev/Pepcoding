ListNode *segregateEvenOdd(ListNode *head)
{
    if(head==NULL or head->next==NULL)
        {
            return head;
        }
        
        
        ListNode* temp=head;
        ListNode* oddstart=new ListNode(-1);
        ListNode* evenstart=new ListNode(-1);
        ListNode* t1=oddstart;
        ListNode* t2=evenstart;
        
       while(temp!=NULL)
       {
           if(temp->val%2==0)
           {
               t2->next=temp;
               t2=temp;
           }
           else
           {
               t1->next=temp;
               t1=temp;
           }
           temp=temp->next;
       }
       t1->next=NULL;
       t2->next=NULL;
       
       t2->next=oddstart->next;
       return evenstart->next;
}