
// post order appproach
public static node leftcloned(Node node)
{
	if(node==null)
	{
		return null;
	}

	Node l=leftcloned(node.left);
	Node r=leftcloned(node.right);

	node nn=new Node(node.data,l,null);
	node.left=nn;
	r=null;
	return node;

}


// pre order appproach
public static node leftcloned(Node node)
{
	if(node==null)
	{
		return null;
	}

	Node temp=new Node(node.data,node.left!=null?node.left:null,null);
	node.left=temp;

	Node l=leftcloned(node.left.left);
	Node r=leftcloned(node.right);
	
	return node;

}