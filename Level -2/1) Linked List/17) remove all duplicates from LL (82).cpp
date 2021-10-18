ListNode* deleteDuplicates(ListNode* head) {
        
        
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* dummy= new ListNode(-1);
        ListNode* itr=dummy;
        itr->next=head;
        ListNode* curr=head->next;
        
        while(curr!=NULL)
        {
            bool flag=false;
            while(curr!=NULL and itr->next->val==curr->val)
            {
                flag=true;
                curr=curr->next;
            }
            if(flag==true)
                itr->next=curr;
            else
                itr=itr->next;
            
            if(curr!=NULL) curr=curr->next;
        }
        
        return dummy->next;
        
    }