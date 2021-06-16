    public Node getMidNode(Node node)
    {
        Node slow=node;
        Node fast=node.next;
        
        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        
        return slow;
    }
    
    public Node reverse(Node node)
    {
        Node prev=null;
        Node curr=node;
        
        while(curr!=null)
        {
            Node next1=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next1;
            
        }
        return prev;
    }
    public void fold() {
      // write your code here
      
      if(this.head==null || this.head.next==null || this.head.next.next==null)
      {
          return ;
      }
      
      Node head1=this.head;
      Node mid=getMidNode(head1);
      Node head2=mid.next;
      mid.next=null;
      
      head2=reverse(head2);
      
      Node t1=head1;
      Node t2=head2;
      Node prev=head1;
      
      while(t1!=null && t2!=null)
      {
        Node n1=t1.next;
        Node n2=t2.next;
        
        t1.next=t2;
        t1=n1;
        
        prev=t1==null?prev:t1;
        
        t2.next=n1;
        t2=n2;
        
        prev=t2==null?prev:t2;
      }
      
      this.head=head1;
      this.tail=prev;
      
      
    }