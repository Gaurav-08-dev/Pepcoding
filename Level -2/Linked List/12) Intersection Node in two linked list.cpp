/* Using flloyd cycle detection*/

ListNode *detectCycle(ListNode *head) {
     
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                break;
            }
        }
        
        if(fast==NULL or fast->next==NULL)
        {
            return nullptr;
        }
        
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tail=headA;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=headA;
        
        ListNode* res=detectCycle(headB);
        
        tail->next=NULL;
        return res;
    }



    /**********************************************************************************/

    /* Using difference method*/

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