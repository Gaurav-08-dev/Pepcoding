ListNode* reverse(ListNode* head, ListNode* ptr){

	ListNode* curr=head;
	ListNode* prev=NULL;

	while(curr!=ptr)
	{
		ListNode* n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}

	return prev;
}


ListNode* reverseKGroup(ListNode* head,int k)
{
	ListNode* ptr=head;

	for(int i=0;i<k;i++)
	{
		if(!ptr) return head;
		ptr=ptr->next;
	}

	ListNode* ans=reverse(head,ptr);
	head->next=reverseKGroup(ptr,k);
	return ans;
}