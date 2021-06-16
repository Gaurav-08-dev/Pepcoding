void traversals(node root)
{
	queue<Node> q;
	q.push(root);

	while(qu.size()>0)
	{
		Node rem=q.remove();

		cout<<q.data;

		for(Node child: root.children)
		{
			q.push(child);
		}
	}
}