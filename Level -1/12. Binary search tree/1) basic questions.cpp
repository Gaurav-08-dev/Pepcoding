public static int size(Node node) {
  
  if(node==null) return 0;

  int ls=size(node.left);
  int rs=size(node.right);

  int ts=ls + rs + 1;

  return ts;
}


public static int sum(Node node) {
  
          if(node == null) return 0;

      int lsum = sum(node.left);
      int rsum = sum(node.right);
      return lsum + rsum + node.data;
}

public static int max(Node node) {
  
  if(node==null) return Integer.MIN_VALUE;
  else if(node.right==null)
  {
    return node.data;
  }
  else 
  {
    return max(node.right);
  }
}

public static int min(Node node) {
  
      if(node==null) return Integer.MAX_VALUE;
  else if(node.left==null)
  {
    return node.data;
  }
  else 
  {
    return min(node.left);
  }

}

public static boolean find(Node node, int data){
  
  if(node==null) return false;

  if(data > node.data)
  {
    return find(node.right, data);
  }
  else if(data < node.data)
  {
    return find(node.left, data);
  }
  else{
    return true;
  }


}  