void reverse(Node node)
{
	if(node.next==null)
	{
		this.head=node;
		return;
	}

	reverse(node.next);
	node.next.next=node;
}

void helper()
{
	Node temp=this.head;
	reverse(temp);
	temp.next=null;
	this.tail=temp;
}