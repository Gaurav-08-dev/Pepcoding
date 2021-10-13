ListNode* reverse(ListNode* head,ListNode* ptr){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr!=ptr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        // cout<<prev->val<<"\n";
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        ListNode* ptr=head;
        
        for(int i=0;i<k;i++)
        {
            if(!ptr) return head;
            ptr=ptr->next;
        }
        // cout<<"ptr-> "<<ptr->val<<" ";
        ListNode* ans=reverse(head,ptr);
        head->next=reverseKGroup(ptr,k);
        return ans;
    }