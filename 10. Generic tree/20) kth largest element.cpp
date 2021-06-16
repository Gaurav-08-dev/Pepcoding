  public static int kthLargest(Node node, int k){
      
      int data=Integer.MAX_VALUE;
      for(int i=0;i<k;i++)
      {
        floor=Integer.MIN_VALUE;
        ceilAndFloor(node,data);
        data=floor;
      }
      
      return data;
  }
