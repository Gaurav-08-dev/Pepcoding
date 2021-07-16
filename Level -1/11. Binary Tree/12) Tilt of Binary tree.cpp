
  static int tilt = 0;
  
  public static int sum(Node node)
  {
    if(node==null)
    {
        return 0;
    }
    int l=sum(node.left);
    int r=sum(node.right);
    
    tilt+=Math.abs(l-r);
    
    return l+r+node.data;
    
  }
  public static int tilt(Node node)
  {
      tilt=0;
      sum(node);
      return tilt;
    
  }

 