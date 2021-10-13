/* O(n*n) method */

int left=0,right=this.size;
while(left<right)
{
	Node lnode=getNthNode(left);
	Node rnode=getNthNode(right);

	if(lnode.data!=rnode.data)
	{
		return false;
	}

	left++; right--;
}

return false;




/* O(n) method */



Node getMidNode(Node node)
{
	Node slow=node;
	Node fast=node;

	while(fast!=null and fast.next!=null)
	{
		slow=slow.next;
		fast=fast.next.next;
	}

	return slow;
}

Node reversePointer(Node node)
{
	Node prev=null;
	Node curr=node;

	while(curr!=null)
	{
		Node next=curr.next;
		curr.next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

int main(){

Node head1=this.head;

Node mid=getMidNode(head1);

Node head2=mid.next;
mid.next=null;

head2=reversePointer(head2);

Node t1=head1;
Node t2=head2;

bool res=true;

while(t1!=null and t2!=null)
{
	if(t1.data!=t2.data){ result=false; break;}

	t1=t1.next;
	t2=t2.next;

}

// maintain original list
head2=reversePointer(head2);

mid.next=head2;

return res;
}



/***************** USING FLOYD's CYCLE DETECTION ********************/
bool isPalindrome(ListNode* head) {
        
        ListNode* slow=head, *fast=head, *prev,*curr;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev=slow,slow=slow->next,prev->next=NULL;
        
        while(slow)
        {
            curr=slow->next;
            slow->next=prev;
            prev=slow;
            slow=curr;
        }
        
        fast=head,slow=prev;
        
        while(slow)
        {
            if(fast->val!=slow->val)
            {
                return false;
            }
            else
            {
                fast=fast->next; 
                slow=slow->next;
            }
        }
        
        return true;
    }