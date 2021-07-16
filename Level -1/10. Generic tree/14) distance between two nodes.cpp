int distanceBetweenNodes(Node node, int d1, int d2){
    
    ArrayList<Integer> n1=nodeToRootPath(node,d1);
	ArrayList<Integer> n2=nodeToRootPath(node,d2);

	int i=n1.size()-1;
	int j=n2.size()-1;
	

	while(i>=0 && j>=0 && n1.get(i)==n2.get(j))
	{
		i--;
		j--;
	}

	return i + j + 2;
    
  }