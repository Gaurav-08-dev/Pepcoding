
public static int diameter=0;


public static int heightOfDiameter(TreeNode root)
{
  if(root==null) return -1;
  
  int lh=heightOfDiameter(root.left);
  int rh=heightOfDiameter(root.right);
  
  diameter=Math.max(diameter,lh+rh+2);
  
  return Math.max(lh,rh)+1;
  
}

public static int diameterOfBinaryTree(TreeNode root) {
  
  diameter=0;
  
  heightOfDiameter(root);
  
  return diameter;
}




	  return root;
