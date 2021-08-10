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


ListNode* reverse(ListNode* head)
{
    ListNode* prev=NULL;
    ListNode* curr=head;
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


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1==NULL or l2==NULL)
    {
        return l1==NULL?l2:l1;
    }
    
    // reverse both the number
    ListNode* n1=reverse(l1);
    ListNode* n2=reverse(l2);
    
    ListNode* result=new ListNode(-1);
    ListNode* temp=result;
    
    ListNode* i=n1;
    ListNode* j=n2;
    
    int carry=0;
    
    while(carry!=0 or i!=NULL or j!=NULL)
    {
        int ival=i==NULL?0:i->val;
        int jval=j==NULL?0:j->val;
        
        i=i==NULL?NULL:i->next;
        j=j==NULL?NULL:j->next;
        
        int sum=ival + jval + carry;
        ListNode* val=new ListNode(sum%10);
        carry=sum/10;
        temp->next=val;
        temp=val;
    }
    
     result=reverse(result->next);
    return result;
    
}

// Input_code===================================================

ListNode *makeList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
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
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}