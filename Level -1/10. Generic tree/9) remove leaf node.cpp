
/* O(n*n)  */

public static void leaf(Node node)
{
	for(int i=node.children.size()-1;i>=0;i--)
	{
		Node child=node.children.get(i);

		if(child.children.size()==0)
		{
			node.children.remove(i);
		}
	}

	for(Node child: node.children)
	{
		leaf(child);
	}
}

/* ------------------------------------------- */
// O(n) method

public static void leaf(Node node)
{
	ArrayList<Node> st=new ArrayList<>();

	for(Node child: node.children)
	{
		if(child.children.size()!=0)
		{
			st.add(child);
		}
	}

	node.children=st;
	
	for(Node child: node.children)
	{
		leaf(child);
	}

}