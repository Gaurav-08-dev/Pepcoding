Node* getmid(Node* head)
{
        Node* slow = head;
        Node* fast = head->right;

        while(fast!=NULL && fast->right != NULL) {
            slow = slow->right;
            fast = fast->right->right;
        }
        return slow;
}
 Node creationBST(Node* head)
 {
     if(head == NULL) return nullptr;
 
        Node* mid = getmid(head);
        if(mid->left != NULL) {
            mid->left->right = NULL;
            mid->left = NULL;
        }
 
        Node* head2 = mid->right;
        if(mid->right != NULL) {
            mid->right->left = NULL;
            mid->right = NULL;
        }
 
        if(mid != head) 
            mid->left = creationBST(head);
        mid->right = creationBST(head2);
 
        return mid;
 }

Node *SortedDLLToBST(Node* head)
{
    Node* root=creationBST(head);
    return root;
}