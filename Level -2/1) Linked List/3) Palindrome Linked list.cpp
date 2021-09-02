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

    ListNode *getMidNode(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    
    ListNode* reverse(ListNode* head) {
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
    
    

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        {
            return true;
        }
        ListNode* head1=head;
        ListNode* midNode=getMidNode(head1);
        ListNode* head2=midNode->next;
        midNode->next=NULL;
        
        head2=reverse(head2);
        ListNode* t1=head1;
        ListNode* t2=head2;
        bool res=true;

        while(t1!=NULL and t2!=NULL)
        {
            if(t1->val!=t2->val){ res=false; break;}

            t1=t1->next;
            t2=t2->next;

        }

        
        head2=reverse(head2);

        midNode->next=head2;

        return res;
        
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}