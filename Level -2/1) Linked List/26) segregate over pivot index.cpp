ListNode* segregate(ListNode* head, int pivotIdx)
{
  ListNode* pivot=head;
  
  for(int i=0;i<pivotIdx;i++)
  {
    pivot=pivot->next;
  }
  
  ListNode* s=new ListNode(-1);
  ListNode* g=new ListNode(-1);
  
  ListNode* t1=s,*t2=g,*temp=head;
  
  while(temp!=NULL){
      if(temp!=pivot)
      {
        if(temp->val<=pivot->val)
        {
            t1->next=temp;
            t1=temp;
        }
        else
        {
            t2->next=temp;
            t2=temp;
        }
      }
      temp=temp->next;
  }
  
  t2->next=NULL;
  pivot->next=g->next;
  t1->next=pivot;
  
  return s->next;
  
}