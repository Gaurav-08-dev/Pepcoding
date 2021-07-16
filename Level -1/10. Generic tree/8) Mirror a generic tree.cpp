public static void mirror(Node node)
{
	for(Node child: node.children)
	{
		mirror(child);
	}

	int left=0;
	int right=node.children.size()-1;

	while(left<right)
	{
		Node temp=node.children.get(left);
		node.children.set(temp,node.children.get(right));
		node.children.set(right,temp);
		left++;
		right--;
	}
}