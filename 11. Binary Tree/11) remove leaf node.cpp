// with return type


// Approach 1

public static Node removeLeaves(Node node){

if(node==null)
{
	return null;
}

if(node.left!=null && node.right!=null)
{
	node.left=removeLeaves(node.left);
	node.right=removeLeaves(node.right);
}

else if(node.right!=null)
{
	node.left=removeLeaves(node.left);
}
else if(node.left!=null)
{
	node.right=removeLeaves(node.right);
}
else
{
	// leaf -> removal of node
	node=null;
}

return node;

}


// Approach 2

public static Node removeLeaves(Node node)
{

	if(node==null)
	{
	    return null;
	}

	if(node.left==null && node.right==null)
	{
	    return null;
	}

	Node l= removeLeaves(node.left);
	Node r= removeLeaves(node.right);
	node.left=l;
	node.right=r;

	return node;
}



