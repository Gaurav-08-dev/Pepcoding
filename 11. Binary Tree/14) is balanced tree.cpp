// for every node the gap between height's of 
// it's left and right subtree is not mare than 1

public static class Bpair{

	int ht;
	boolean isBalance;

	public Bpair()
	{
		this.ht=-1;
		this.isBalance=true;
	}
}

public static Bpair isBalanced(Node node)
{
	if(node==null)
	{
		return new Bpair();
	}

	Bpair lres=isBalanced(node.left);
	Bpair rres=isBalanced(node.right);

	boolean factor=Math.abs(lres.ht-rres.ht)<2; 
	Bpair mres=new Bpair();

	mres.ht=Math.max(lres.ht,rres.ht) + 1;

	mres.isBalance=factor && lres.isBalance && rres.isBalance;
	return mres;
}



System.out.println(isBalanced(root).isBalance);