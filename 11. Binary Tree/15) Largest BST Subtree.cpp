public static class BSTPair{

	int min,max;
	boolean isbst;
	int size;

	public BSTPair()
	{
		min=Integer.MAX_VALUE;
		max=Integer.MIN_VALUE;
		isbst=true;
		size=0;
	}

}

static int sz=0;
static Node bstNode=null;
public static BSTPair largestBST(Node node)
{
	if(node==null) return new BSTPair();

	BSTPair lres=largestBST(node.left);
	BSTPair rres=largestBST(node.right);

	boolean status = lres.max < node.data && rres.min > node.data;
	
	BSTPair mres=new BSTPair();
	mres.min=Math.min(node.data,Math.min(lres.min,rres.min));
	mres.max=Math.max(node.data,Math.max(lres.max,rres.max));
	mres.isbst=lres.isbst && rres.isbst && status;
	mres.size= lres.size + rres.size +1;
	
	if(mres.isbst==true && mres.size > sz)
	{
		bstNode = node;
		sz=mres.size;
	}

	return mres;
} 



// inside main fucntion

largestBST(root);
System.out.println(bstNode.data + "@" + sz);