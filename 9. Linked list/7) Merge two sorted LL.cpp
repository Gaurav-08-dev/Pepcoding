  public static LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2) {
            
        LinkedList l3=new LinkedList();
        Node temp1= l1.head;
        Node temp2=l2.head;
        
        while(temp1!=null && temp2!=null)
        {
            if(temp1.data < temp2.data)
            {
                l3.addLast(temp1.data);
                temp1=temp1.next;
            }
            else
            {
                l3.addLast(temp2.data);
                temp2=temp2.next;
            }
        }
        
        
        while(temp1!=null)
        {
            l3.addLast(temp1.data);
            temp1=temp1.next;
        }
        
        while(temp2!=null)
        {
            l3.addLast(temp2.data);            
            temp2=temp2.next;
        }
            
            return l3;
            

}



