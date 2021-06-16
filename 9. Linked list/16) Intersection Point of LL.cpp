 public static int findIntersection(LinkedList one, LinkedList two){
      // write your code here
      int size1=one.size;
      int size2=two.size;
      
      Node temp1=one.head;
      Node temp2=two.head;
      
      
      if(size1>size2)
      {
        int diff=size1-size2;
        
        for(int i=0;i<diff;i++)
        {
            temp1=temp1.next;
        }
      }
      else
      {
        int diff=size2-size1;
        
        for(int i=0;i<diff;i++)
        {
            temp2=temp2.next;
        } 
      }
      
      while(temp1!=temp2)
      {
        temp1=temp1.next;
        temp2=temp2.next;
      }
      
      return temp1.data;
      
      
      
    }