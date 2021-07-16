
public static Node getTail(Node node)
{
	Node tail=node;

	while(tail.children.size()==0)
	{
		tail=tail.children[0];
	}

return tail;
}


public static void linearize(Node node)
{
	for(Node child: node.children)
	{
		linearize(child);
	}

	for(int i =node.children.size()-2;i>=0;i--)
	{
		Node last=node.children.get(i+1); //get last child
		Node slast=node.children.get(i); //get second last child

		node.children.remove(i+1); // remove last children
		Node tail=getTail(slast); // get tail of second last children

		tail.children.add(last);
	}
}




/* ---------------------------------------------------- */

Node linearize2(Node node)
{

	if(node.children.size()==0)
	{
		return node;
	}

	Node lastNode=node.children.get(node.children.size()-1);
	Node lastTail=linearize2(lastNode);

	for(int i=node.children.size()-2;i>=0;i--)
	{
		Node rem=node.children.remove(i+1);

		Node stail= linearize2(node.children.get(i));
		stail.children.add(rem);
	}

	return tail;
}