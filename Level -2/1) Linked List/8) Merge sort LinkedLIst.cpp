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

ListNode* getMid(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head->next;
    
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}
ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
{
    if(l1==NULL or l2==NULL) 
        return l1==NULL?l2:l1;
        
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
ListNode *mergeSort(ListNode *head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    
    ListNode* mid=getMid(head);
    ListNode* head1=mid->next;
    mid->next=NULL;
    
    head = mergeSort(head);
    head1 = mergeSort(head1);
    
    ListNode* res=mergeTwoList(head,head1);
    
    return res;
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

ListNode *createList(int n)
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

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}