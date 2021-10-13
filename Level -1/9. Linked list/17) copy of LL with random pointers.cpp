/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
//         clone linked list without random pointer
        
        Node* dummy=new Node(-1);
        Node *t1=dummy, *t2=head;
        
        while(t2!=NULL)
        {
            Node *nn =new Node(t2->val);
            t1->next=nn;
            t1=nn;
            t2=t2->next;
        }
        
        Node* head2=dummy->next; // head of new copied linked list
        
        t1=head,t2=head2;
        
//         connect original and copied LL in zig-zag order
        
        while(t1!=NULL and t2!=NULL)
        {
            Node *n1=t1->next;
            Node *n2=t2->next;
            
            t1->next=t2;
            t2->next=n1;
            t1=n1;
            t2=n2;
        }
        
//         set random pointer
        t1=head;
        while(t1!=NULL)
        {
            t1->next->random=t1->random==NULL ? NULL:t1->random->next;
            t1=t1->next->next;
        }
        
//         rearrange the original LL
        
        Node* d1=new Node(-1);
        t1=d1;
        Node* d2=new Node(-1);
        t2=d2;
        
        Node* temp=head;
         while(temp!=NULL)
        {
            t1->next=temp;
            t2->next=temp->next;
            
            t1=t1->next;
            t2=t2->next;
            temp=temp->next->next;
        }
        
        t1->next=NULL;
        t2->next=NULL;
        
        return d2->next;
        
        
    }
};