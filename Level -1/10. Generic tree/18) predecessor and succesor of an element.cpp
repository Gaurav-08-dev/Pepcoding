
  static Node predecessor;
  static Node successor;
  static int state=0;

predecessorAndSuccessor(Node node, int data) 
  {
      if(state==0)
      {
        if(node.data==data)
        {
            state++;
        }
        else
        {
            predecessor=node;
        }
      }
      else if(state==1)
      {
          successor=node;
          state++;
          return;
      }
      
    for(Node child: node.children)
    {
        if(state<2)
        {
            predecessorAndSuccessor(child,data);
        }
        
    }
}
