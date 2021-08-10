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

ListNode *reverse(ListNode *head)
{
      if(head == NULL)
            return head;
        if(head->next==NULL)
        {
            return head;
        }
        
        ListNode *prev=NULL;
        ListNode *curr=head;
        
        while(curr!=NULL)
        {
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        
        head=prev;
        return head;
    
    
}


/* Reverse usin add first */

void addFirst(ListNode* head,ListNode* tHead,ListNode* tTail)
{
    if(tHead==NULL)
    {
        tHead=tTail=NULL;
    }
    else
    {
        head->next=tHead;
        head=tHead;
    }
}

ListNode* reverse(ListNode* head)
{
    ListNode* tHead=NULL;
    ListNode* tTail=NULL;

    ListNode* n=head;
    while(n!=NULL)
    {
        ListNode* i=n;
        n=i->next;
        i->next=NULL;
        addFirst(i,tHead,tTail);
    }
    return tHead;
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

    ListNode *head = reverse(dummy->next);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}