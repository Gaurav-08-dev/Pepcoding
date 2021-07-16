public static void levelOrder(Node node) {
    
    Queue<Node> q=new ArrayDeque<>();
    
    q.add(node);
    
    while(q.size()>0)
    {
        int sz=q.size();
        
        while(sz-- > 0)
        {
            Node nn=q.remove();
            System.out.print(nn.data + " ");    
            
            if(nn.left!=null)
            {
                q.add(nn.left);
            }
            if(nn.right!=null)
            {
                q.add(nn.right);
            }
        }
        
        System.out.println();
        
    }    
  }