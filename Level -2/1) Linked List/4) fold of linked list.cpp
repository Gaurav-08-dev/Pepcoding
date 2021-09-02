#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

   
    ListNode* getMidNode(ListNode* node)
    {
        ListNode* slow=node;
        ListNode* fast=node->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode*  prev=NULL;
        ListNode*  curr=node;
        
        while(curr!=NULL)
        {
            ListNode*  next1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
            
        }
        return prev;
    }
    
    void fold(ListNode* head) {
        
        if(head==NULL || head->next==NULL || head->next->next==NULL)
      {
          return ;
      }
      
      ListNode*  head1=head;
      ListNode*  mid=getMidNode(head1);
      ListNode*  head2=mid->next;
      mid->next=NULL;
      
      head2=reverse(head2);
      
      ListNode*  t1=head1;
      ListNode*  t2=head2;
      ListNode*  prev=head1;
      
      while(t1!=NULL && t2!=NULL)
      {
        ListNode*  n1=t1->next;
        ListNode*  n2=t2->next;
        
        t1->next=t2;
        t1=n1;
        
        prev=t1==NULL?prev:t1;
        
        t2->next=n1;
        t2=n2;
        
        prev=t2==NULL?prev:t2;
      }
      
      head=head1;
      
    }

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}