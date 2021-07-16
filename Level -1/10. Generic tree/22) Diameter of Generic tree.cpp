// Approach 1

public static int diameter(Node node)
{
	int mh=-1;
	int smh=-1;


	for(Node chlid: node.children)
	{
		int ht=height(child);

		if(ht>=mh)
		{
			smh=mh;
			mh=ht;
		}
		else if(ht > smh)
		{
			smh=ht;
		}
	}

	int dfc=0;

	for(Node child:node.children)
	{
		dfc=Math.max(diameter(child),dfc);
	}

	return Math.max(dfc,mh+smh+2);
}

// Approach 2

public static int diameter=0;
public static int heightForDiameter(Node node)
{
    int maxHt=-1;
    int smaxHt=-1;
    
    for(Node child: node.children)
    {
        int ht=heightForDiameter(child);
        if(ht>=maxHt)
        {
            smaxHt=maxHt;
            maxHt=ht;
        }
        else if(ht > smaxHt)
        {
            smaxHt=ht;
        }
    }
    
    diameter=Math.max(diameter, maxHt+smaxHt+2);
    return maxHt+1;
}