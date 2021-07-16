boolean find(Node node,data)
{
	if(node.data==null)
	{
		return false;
	}

	if(node.data==data)
	{
		return true;
	}

	boolean lres=find(node.left,data);
	if(lres==true)
	{
		return true;
	}
	boolean rres=find(node.right,data);
	if(rres==true)
	{
		return true;
	}

	return false;
}


ArrayList<Integer> nodeToRootPath(Node node,int data)
{
	if(node==null)
	{
		return new ArrayList<>();
	}

	if(node.data==data)
	{
		 ArrayList<Integer> bres=new ArrayList<>();
          bres.add(node.data);
          return bres;
	}

	     ArrayList<Integer> lres=nodeToRootPath(node.left,data);
      if(lres.size()>0)
      {
          lres.add(node.data);
          return lres;
      }
      ArrayList<Integer> rres=nodeToRootPath(node.right,data);
            if(rres.size()>0)
      {
          rres.add(node.data);
          return rres;
      }
      
      return new ArrayList<Integer>();

}
