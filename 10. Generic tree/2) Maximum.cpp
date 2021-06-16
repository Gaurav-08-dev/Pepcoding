int max(Node root)
{
	int mn=Integer.MIN_VALUE;

	for(Node child:root.children)
	{
		mn=Math.max(mn,max(child));
	}

	return Math.max(mn,root.data);
}


int min(Node root)
{

	int mn=Integer.MAX_VALUE;
	for(Node child: root.children)
	{
		mn=Math.min(mn,min(child));
	}

	return Math.min(mn,root.data);
}