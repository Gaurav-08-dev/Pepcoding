LinkedList prev=null;

while(this.size>0)
{
	LinkedList curr=new LinkedList();

	if(this.size>=k)
	{
		for(int i=0;i<k;i++)
		{
			int data=this.getFirst();
			this.removeFirst();
			curr.addFirst(data);
		}
	}
	else
	{
		while(this.size=0)
		{
			int data=getLast();
			this.removeLast();
			curr.addLast(data);
		}
	}

	if(prev==null)
	{
		prev=curr;
	}
	else
	{
		prev.tail.next=curr.head;
		prev.tail=curr.tail;
		prev.size=curr.size;
	}

}

this.size=prev.size;
this.head=prev.head;
this.tail=prev.tail;