ListNode* partition(ListNode* start, ListNode* end){

	int pivotValue=start->val;
	ListNode* p=start,*q=start->next;

	while(q!= end)
	{
		if(pivotValue > q->val)
		{
			p=p->next;
			swap(p->val,q->val);
		}
		q=q->next;
	}
	swap(p->val,start->val);
	return p;
}

void QuickSort(ListNode* start, ListNode* end)
{
	if(start!=end)
	{
		ListNode* mid= partition(start,end);
		QuickSort(start,mid);
		QuickSort(mid->next,end);
	}
}


ListNode *quickSort(ListNode *head)
{
    QuickSort(head,NULL);
    return head;
}
