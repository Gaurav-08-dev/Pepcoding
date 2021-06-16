 public static LinkedList addTwoLists(LinkedList one, LinkedList two) {
      // write your code here
      
      Node head1=one.head;
      Node head2=two.head;
      
    //   Dont change original list
    
    // 1. reverse Linked List
    
    head1=reverse(head1);
    head2=reverse(head2);
    
    // 2. add
    
    int carry=0;
    Node i=head1;
    Node j=head2;
    
    LinkedList result=new LinkedList();
    while(i!=null || j!=null || carry!=0)
    {
        int ival=i==null?0:i.data;
        i=i==null?null:i.next;
        
        int jval=j==null?0:j.data;
        j=j==null?null:j.next;
        
        int sum=ival + jval + carry;
        int val=sum%10;
        carry=sum/10;
        result.addFirst(val);
    }
    
    // 3. Make original list
    head1=reverse(head1);
    head2=reverse(head2);
    
    // 4. return result
    return result;
    }
    


    
    // ADDITION USING RECURSION
    
    public static int additionHelper(Node one,int s1,Node two,int s2,LinkedList res)
    {
        if(one==null && two==null)
        {
            return 0;
        }
        
        int d1=one.data;
        int d2=two.data;
        
        int sum=0;
        if(s1>s2)
        {
            int carry=additionHelper(one.next,s1-1,two,s2,res);
            sum=d1+carry;
            
            
        }
        else if(s1<s2)
        {
            int carry=additionHelper(one,s1,two.next,s2-1,res);
           sum=d2+carry;
            
        }
        else
        {
            int carry=additionHelper(one.next,s1-1,two.next,s2-1,res);
           sum=d1+d2+carry;
            
        }
        res.addFirst(sum%10);
        return sum/10;
    }
    
  public static LinkedList addTwoLists(LinkedList one, LinkedList two)
  {
    LinkedList res=new LinkedList();
    
    int carry=additionHelper(one.head,one.size,two.head,two.size,res);
    
    if(carry>0)
    {
        res.addFirst(carry);
    } 
    return res;
  }