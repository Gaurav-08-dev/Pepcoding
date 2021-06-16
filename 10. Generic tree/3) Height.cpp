int height(Node root)
{
	int h=-1;

	for(Node child: root.children)
	{
		h+=max(h,height(child));
	}

	return h+1;

}