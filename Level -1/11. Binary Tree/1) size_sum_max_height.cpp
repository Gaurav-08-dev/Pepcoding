  public static int size(Node node) {
    // write your code here
    
    if(node==null)
    {
        return 0;
    }
    int ls=size(node.left);
    int rs=size(node.right);
    
    return ls + rs + 1;
  }

  public static int sum(Node node) {
    // write your code here
    
    if(node==null)
    {
        return 0;
    }
    
    int ls=sum(node.left);
    int rs=sum(node.right);
    
    return ls + rs + node.data;
  }

  public static int max(Node node) {
    // write your code here
    
    if(node==null)
    {
        return Integer.MIN_VALUE;
    }
    
    int lmax=max(node.left);
    int rmax=max(node.right);
    
    return Math.max(node.data,Math.max(lmax,rmax));
  }

  public static int height(Node node) {
    // write your code here
    if(node==null)
    {
        return -1;
    }
    
    int hl=height(node.left);
    int hr=height(node.right);
    
    return Math.max(hl,hr) + 1;
  }