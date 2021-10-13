/*********************** SIZE DIFFERENCE METHOD ****************************/

  int size(ListNode* head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // using difference method
        
        int s1=size(headA);
        int s2=size(headB);
        
        ListNode* t1=headA;
        ListNode* t2=headB;
        
        if(s1 > s2)
        {
            for(int i=0;i<s1-s2;i++)
            {
                t1=t1->next;
            }
        }
        else
        {
        for(int i=0;i<s2-s1;i++)
            {
                t2=t2->next;
            }
        
        }
        
        while(t1!=NULL)
        {
            if(t1==t2) return t1;
            t1=t1->next;
            t2=t2->next;
        }
        
        return NULL;
    }

/********************* TWO POINTER SOLUTION *****************/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while(ptr1 != ptr2){
      if(ptr1 == NULL){
        ptr1 = headB;
      }
      else{
        ptr1 = ptr1 -> next;
      }
      if(ptr2 == NULL){
        ptr2 = headA;
      }
      else{
        ptr2 = ptr2 -> next;
      }
    }
    return ptr1;
  }

