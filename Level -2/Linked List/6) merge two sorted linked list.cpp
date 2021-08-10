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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    
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
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}