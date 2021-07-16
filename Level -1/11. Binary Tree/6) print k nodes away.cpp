 public static void printKDown(Node node,Node blockage,int k)
    {
        if(node==null || node == blockage ) return;
        
        if(k==0)
        {
            System.out.println(node.data);
            return;
        }
        
        printKDown(node.left,blockage,k-1);
        printKDown(node.right,blockage,k-1);
        
    }
    public static ArrayList<Node> nodeToRoot(Node node,int data)
    {
        if(node == null)
        {
            return new ArrayList<>();
        }
        if(node.data==data)
      {
          ArrayList<Node> bres=new ArrayList<>();
          bres.add(node);
          return bres;
      }
      ArrayList<Node> lres=nodeToRoot(node.left,data);
      if(lres.size()>0)
      {
          lres.add(node);
          return lres;
      }
      ArrayList<Node> rres=nodeToRoot(node.right,data);
        if(rres.size()>0)
      {
          rres.add(node);
          return rres;
      }
      
      return new ArrayList<Node>();
    }
    
  public static void printKNodesFar(Node root, int data, int k) {
    
    ArrayList<Node> n2rp=nodeToRoot(root,data);
    Node blockage=null;
    
    for(int i=0;i<n2rp.size() & k>=0;i++)
    {
        Node node=n2rp.get(i);
        printKDown(node,blockage,k);
        k--;
        blockage=node;
    }
  }