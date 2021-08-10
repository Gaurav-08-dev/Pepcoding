/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* Using Priority queue*/
class Compare{
    
    public:
        bool operator()(const ListNode* l,const ListNode* r)
        {
            return l->val > r->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
        {
            return nullptr;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        if(pq.empty())
            return nullptr;
        
        while(!pq.empty())
        {
            ListNode* t=pq.top();
            temp->next=t;
            pq.pop();
            t=t->next;
            if(t!=NULL)
                pq.push(t);
            
            temp=temp->next;
        }
        
        return dummy->next;
        
        
    }
};


/* Using Divide n Conquere method*/


class Solution {
public:
    
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        if(!head1)
            return head2;
        else if(!head2)
            return head1;
        
        ListNode* t1=head1;
        ListNode* t2=head2;
        ListNode* dummy=new ListNode(-1); //l3
        ListNode* temp=dummy; //ptr3
        while(t1 and t2)
        {
            if(t1->val <= t2->val)
            {
                temp->next=new ListNode(t1->val);
                t1=t1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=new ListNode(t2->val);
                t2=t2->next;
                temp=temp->next;
            }
        }
        
        while(t1)
        {
            temp->next=new ListNode(t1->val);
            t1=t1->next;
            temp=temp->next;
        }
         while(t2)
        {
            temp->next=new ListNode(t2->val);
            t2=t2->next;
            temp=temp->next;
        }
        temp=dummy->next;
        delete dummy;
        return temp;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k=lists.size();
        if(k==0) return nullptr;
        else if(k==1) return lists[0];
        else if(k==2) return merge(lists[0],lists[1]);
        
        vector<ListNode*> mergedLists;
        for(int i=0;i<k;i+=2)
        {
            if(i<k-1)
            {
                mergedLists.push_back(merge(lists[i],lists[i+1]));
                
            }
            else
            {
                mergedLists.push_back(lists[i]);
            }
        }
        return mergeKLists(mergedLists);
        
    }
};
/*

Time: O(nlogk) where n is the total number of elements, and k is the number of lists initially given
Space: O(nlogk) since the merging requires an extra space of O(n) for the result list and there are O(logk) calls to it.

*/