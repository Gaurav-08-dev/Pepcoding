void traversals(Node root)
{
	cout<<"Node pre"<<root.data;

	for(Node child: root.children)
	{
		cout<<"Edge pre"<<root.data<<child.data;
		traversals(child);
		cout<<"Edge post"<<root.data<<child.data;
	}

	cout<<"Node post"<<root.data;
}