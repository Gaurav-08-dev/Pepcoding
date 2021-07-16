boolean areSimilar(Node n1,node n2)
{
	if(n1.children.size()!=n2.children.size())
	{
		return false;
	}

	boolean res=true;
	int n=n1.children.size();
	for(int i=0;i<n;i++)
	{
		Node child1=n1.children.get(i);
		Node child2=n2.children.get(n - i - 1);

		res=areSimilar(child1, child2);
		if(res==false)
		{
			return false;
		}
	}
	return res;
}