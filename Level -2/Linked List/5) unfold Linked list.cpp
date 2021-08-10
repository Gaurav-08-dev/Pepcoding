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

ListNode* reverseList(ListNode* head) {
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
void unfold(ListNode *head)
{
    // Make two dummy nodes 1-> oddHead 2-> evenHead
    if(head==NULL or head->next==NULL or head->next->next==NULL)
        return ;
    ListNode *oddHead=new ListNode(-1);
    ListNode *evenHead=new ListNode(-1);
    
    // iterate on list and make connections according to odd and even index
    
    ListNode *t1=oddHead;
    ListNode *t2=evenHead;
    int index=0;
    for(ListNode *i=head;i!=NULL;i=i->next)
    {
        if(index%2==0)
        {
            index++;
           t2->next=i;
           t2=i;
        }
        else
        {
            index++;
            t1->next=i;
            t1=i;
        }
    }
    t1->next=t2->next=NULL;
    
    oddHead=reverseList(oddHead->next);
    t2->next=oddHead;
    
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
    unfold(head);
    printList(head);

    return 0;
}