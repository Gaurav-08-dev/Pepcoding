public void oddEven(){

      // write your code here
    Node ohead=new Node();
    Node temp2=ohead;
     Node ehead=new Node();
     Node temp1=ehead;
     
     Node itr=this.head;
     
     while(itr!=null)
     {
         if(itr.data%2==0)
         {
          temp1.next=itr;
          temp1=temp1.next;
          
         }
         else
         {
             temp2.next=itr;
              temp2=temp2.next;
          
         }
         itr=itr.next;
     }
    
    temp2.next=ehead.next;
    temp1.next=null;
    
    this.head=ohead.next;
    this.tail=temp2.next ==null? temp2:temp1;   
}