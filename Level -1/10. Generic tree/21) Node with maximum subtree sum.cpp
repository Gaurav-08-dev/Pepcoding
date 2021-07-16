// Approach 1

public static int diameter(Node node)
{
	int mh=-1; // max height
	int smh=-1; // second max height

	// finding height from child
	for(Node child: node.children)
	{
		int ht=height(child);
		if(ht>=mh)
		{
			smh=mh;
			mh=ht;
		}
		else if (ht > smh)
		{
			smh=ht;
		}
	}

	int dfc=0; // diameter from child
	for(Node child: node.children)
	{
		dfc=Math.max(diameter(child),dfc);
	}

	return Math.max(dfc,mh+smh+2);

}