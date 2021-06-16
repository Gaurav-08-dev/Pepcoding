public static ArrayList<Integer> ntp(Node node,int data)
{
	if(node.data ==  data)
	{
		ArrayList<Integer> bres=new ArrayList<Integer>();
		bres.add(node.data);
		return bres;
	}

	for(Node child: node.children)
	{ 
		ArrayList<Integer> ans=new ArrayList<>();
		if(ans.size()>0)
		{
			ans.add(node.data);
			return ans;
		}
	}

	return new ArrayList<>();
} 


// Approach 2 -- return null instead of empty arraylist

public static ArrayList<Integer> ntp(Node node,int data)
{
	if(node.data ==  data)
	{
		ArrayList<Integer> bres=new ArrayList<Integer>();
		bres.add(node.data);
		return bres;
	}

	for(Node child: node.children)
	{ 
		ArrayList<Integer> ans=new ArrayList<>();
		// if(ans.size()>0)
		// {
		// 	ans.add(node.data);
		// 	return ans;
		// }

		if(ans!=null)
		{
			ans.add(node.data);
			return ans;
		}
	}

	return null;
} 
