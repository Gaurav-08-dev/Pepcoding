// O(n^2)
public static int min1(Node node)
{
	if(node==null)
	{
		return Integer.MAX_VALUE;

	}

	int lmin=min1(node.left);
	int rmin=min1(node.right);

	return Math.min(node.data,Math.min(lmin,rmin));

}

public static int max1(Node node)
{
	if(node==null)
	{
		return Integer.MAX_VALUE;

	}

	int lmax=max1(node.left);
	int rmax=max1(node.right);

	return Math.max(node.data,Math.max(lmin,rmin));

}


public static boolean isBST1(Node node)
{
	if(node==null) return true;

	// self check

	 int lmax=max1(node.left);
	 int rmin=min1(node.right);

	 if(lmax>node.data || min < node.data) return false;

	 // left && right check

	 return isBST1(node.left) && isBST1(node.right);

}


// O(N) 
public static class BSTPair
{
	int min;
	int max;
	boolean isbst;

	public BSTPair(){
		min=Integer.MAX_VALUE;
		max=Integer.MIN_VALUE;
		isbst=true;
	}

}


public static BSTPair isBST2(Node node)
{
	if(node==null) return new BSTPair();

	BSTPair lres=isBST2(node.left);
	BSTPair rres=isBST2(node.right);

	boolean status = lres.max < node.data && rres.min>node.data;

	BSTPair mres=new BSTPair();
	mres.min=Math.min(node.data,Math.min(lres.min,rres.min));
	mres.max=Math.max(node.data,Math.max(lres.max,rres.max));
	mres.isbst=lres.isbst && rres.isbst && status;

	return mres;

}