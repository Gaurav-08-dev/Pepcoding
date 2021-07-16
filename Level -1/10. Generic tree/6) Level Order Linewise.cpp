// Approach 1: Using 2 queues approach

  public static void levelOrderLinewise(Node node){
    // write your code here
    
    Queue<Node> q=new ArrayDeque<>();
    Queue<Node> cq=new ArrayDeque<>();
    
    q.add(node);
    while(q.size()>0)
    {
        Node rem=q.remove();
        System.out.print(rem.data + " ");;
        for(Node child: rem.children)
        {
            cq.add(child);
        }
        
        
        if(q.size()==0)
        {
            System.out.println();
            Queue<Node> temp=q;
            q=cq;
            cq=temp;
        }
    }
  }


  // Approach 2: Using delimiter -- 

	  // use linked list as a queue

  Queue<Node> qu=new LinkedList<>();

  qu.add(node);
  qu.add(null);

  while(qu.size()>0)
  {
	Node rem=q.remove();

	if(rem==null)
	{
		// hit enter
		cout<<"\n";

		//  if size is more than 0, add null
		if(qu.size()>0)
		{
			qu.add(null);
		}
	}
	else
	{
		// print
		cout<<rem.data;

		// add children
		for(Ndoe child: node.children)
		{
			qu.add(child);
		}
	}
  }



  // Approach 3: level order line wise, using single que, count approach

  Queue<Node> qu=new LinkedList<>();

  qu.add(node);

  while(qu.size()>0)
  {
  	int sz=qu.size();

  	while(sz-- > 0)
  	{
  		//  get + remove

  		Node rem=qu.remove();

  		cout<<rem.data;

  		for(Node child: rem.children)
  		{
  			qu.add(child);
  		}
  	}
  	cout<<"\n";	
  }