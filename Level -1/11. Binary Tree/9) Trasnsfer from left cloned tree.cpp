  public static Node transBackFromLeftClonedTree(Node node){
    if(node==null)
    {
        return null;
    }
    
    Node n=node.left.left;
    node.left=n;
    
    Node l=transBackFromLeftClonedTree(node.left);
    Node r=transBackFromLeftClonedTree(node.right);
    
    return node;
  }