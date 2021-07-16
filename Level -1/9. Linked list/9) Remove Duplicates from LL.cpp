class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head or !head->next)
        {
            return head;
        }
        ListNode* hold=head;
        ListNode* itr=head->next;
        while(itr!=NULL)
        {
            if(hold->val==itr->val)
            {
                itr=itr->next;
            }
            else
            {
                hold->next=itr;
                hold=hold->next;
                itr=itr->next;
            }
        }
        hold->next=itr;
        return head;
    }
    
    
};