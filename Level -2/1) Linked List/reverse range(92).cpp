class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* it = dummy;
        ListNode* pre_it = NULL;
        //traverse till left index
        for(int i = 0; i < left; i++){
            pre_it = it;
            it = it->next;
        }
        
        ListNode* itR = it;
        ListNode* pre_R = pre_it;
        //reverse 
        for(int i = left; i <= right; i++){
            ListNode* forward = itR->next;
            itR->next = pre_R;
            pre_R = itR;
            itR = forward;
        }
        
        //connect
        pre_it->next = pre_R;
        it->next = itR;
		
        return dummy->next;      
    }
};


/********************************************************************/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode* left_node = head; 
        for(int i = 1; i < left; i++) left_node = left_node->next;
        
        ListNode* node = left_node;
        for(int i = 0; i < (right-left+1); i++){
            v.push_back(node->val);
            node = node->next;
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            left_node->val = v[i];
            left_node = left_node->next;
        }
    return head;      
    }
};


/**********************************************************************/

class Solution {
public:
    // standard list reversing
    ListNode* revere(ListNode* head)
    {
        // reversing whole list
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while(curr != nullptr)
        {
            next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)return head;


        // looping over list, to get first node at index 'm'
        // and I gonna also need node at index m-1 
        
        ListNode* beforeReverse = NULL;
        ListNode* headToReverse = head;
        for(int i = 1; i <= m-1; ++i){ // 1 time
            beforeReverse = headToReverse;
            headToReverse = headToReverse->next;
        }
        
        // doing similar thing as above
        // but now I am looking for node at inxed 'n' and 'n+1'
        
        ListNode* afterReverse = NULL;
        ListNode* lastToReverse = head;
        for(int i = 1; i <= n-1; ++i){ // 1 time
            lastToReverse = lastToReverse->next;
        }
        
        afterReverse = lastToReverse->next;
        
        // What I have now i my variables:
        // afterReverse -  first element after reversed part
        // beforeReverse -    last element before reversed part
        // headToReverse -    head of the list to reverse
        // lastToReverse -   last element to reverse
        
        // disconnecting part of list that I want to reverse (*)
        lastToReverse->next = nullptr;

        // reversing disconnected list
        headToReverse = revere(headToReverse);
        
        // dealing with m=1, so I have to change head 
        if(beforeReverse != nullptr)
            beforeReverse->next = headToReverse;
        else
            head = headToReverse;
            
        // finding end of my list...
        while(headToReverse->next!=nullptr)
        {
            headToReverse = headToReverse->next;
        }
        
        // ...and connecting previously (*) disconnected part
        headToReverse->next = afterReverse;
        
        
        
        return head;
    }

};