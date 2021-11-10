/******************* BY CHANGING REFERENCE POINTER ********************/
ListNode *segregate01(ListNode *head)
{
   ListNode* zero=new ListNode(-1);
        ListNode* one=new ListNode(-1);
        ListNode* z=zero,*o=one,*itr=head;
        
        while(itr!=NULL)
        {
            if(itr->val==0)
            {
                z->next=itr;
                z=itr;
            }
            else
            {
                o->next=itr;
                o=itr;
            }
            itr=itr->next;
        }
        
        z->next=o->next=NULL;
        
        z->next=one->next;
        return zero->next;
}

/********************* BY SWAPPING NODE *****************************/
 

ListNode *segregate01(ListNode *head)
{
    ListNode *i=head,*j=head;

    while(i!=NULL)
    {
    	if(i->val==0)
    	{
    		swap(i->val,j->val);
    		i=i->next;
    		j=j->next;
    	}
    	else
    	{
    		i=i->next;
    	}
    }

    return head;
}
