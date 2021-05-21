class Solution {
public:
    
       
        
    
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* m=head;
        
        while(fast and fast->next)
        {
            m=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        m->next=NULL;
        ListNode* first=sortList(head);
        ListNode* second=sortList(slow);
        ListNode* ans=mergeTwoSortedLL(first,second);
        return ans;
        
        
    }
    
     ListNode* mergeTwoSortedLL(ListNode* h1,ListNode* h2)
    {
       
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(h1!=NULL and h2!=NULL)
        {
            if(h1->val < h2->val)
            {
                temp->next=h1;
                temp=temp->next;
                h1=h1->next;
            }
            else
            {
                temp->next=h2;
                temp=temp->next;
                h2=h2->next;
            }
        }
        if(h1==NULL)
        {
            temp->next=h2;
        }
        if(h2==NULL)
        {
            temp->next=h1;
        }
        
        return dummy->next;
    }
};