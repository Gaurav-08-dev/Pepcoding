// Using global variable

static int max=Integer.MIN_VALUE;
static int min=Integer.MAX_VALUE;
static int ht= 0;
static int size=0;


public static void multisolver(Node node,int depth)
{
	min=Math.min(min,node.data);
	max=Math.max(max,node.data);
	ht=Math.max(ht,depth);
	sz+=1;

	for(Node child: child.children)
	{
		multisolver(child,depth+1);
	}
}

public static void multisolution(Node node)
{
	max=Integer.MIN_VALUE;
	min=Integer.MAX_VALUE;
	ht= 0;
	size=0;

multisolver(node,0);

cout<<min<<max<<size<<ht;

}


// using return type

public static class multiSolver{

	int max;
	int min;
	int ht;
	int size;

	public multiSolver(int min,int max,int ht, int size)
	{
		this.min=min;
		this.max=max;
		this.size=size;
		this.ht=ht;
	}

	
	// public multiSolver()
	// {
	// 	this.min=Integer.MAX_VALUE;
	// 	this.max=Integer.MIN_VALUE;
	// 	this.ht=-1;
	// 	this.size=0;
	// }
}

public static multiSolver mSolver2(Node node)
{
	multiSolver mres=new multiSolver(node.data,node.data,-1,1);

	for(Node child: child.children)
	{
		multiSolver rres=mSolver2(child);
		mres.min=Math.min(mres.min,rres.min);
		mres.max=Math.max(mres.max,rres.max);
		mres.ht=Math.max(mres.ht,rres.ht);
		mres.sz+=rres.size;
	}

	mres.ht+=1;
	return mres;
}
