ListNode *removeDuplicates(ListNode *head)
{
    ListNode* hold=head;
    ListNode* curr=head->next;
    
    while(curr!=NULL)
    {
        if(hold->val == curr->val)
        {
            curr=curr->next;
        }
        else
        {
            
        hold->next=curr;
        hold=hold->next;
        curr=curr->next;
        }
    }
    hold->next=curr;
    return head;
}