

/******************** BY CREATING A NEW LINKED LIST ******************/
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


/************************ WHEN ONLY HEAD POINTER IS GIVEN **************************/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        
    ListNode *one=l1;
    ListNode *two=l2;
    ListNode *three=new ListNode(-1);
    ListNode *temp=three;
    while(one!=NULL and two!=NULL)
    {
        if(one->val > two->val)
        {
            temp->next=two;
            two=two->next;
            temp=temp->next;
        }
        else
        {
            temp->next=one;
            one=one->next;
            temp=temp->next;
        }
    }
    
    if(one == NULL)
    {
        temp->next=two;
    }
    
    else
    {
        temp->next=one;
    }
    
    return three->next;
    }