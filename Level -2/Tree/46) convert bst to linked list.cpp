/* BST TO LINKED LIST* /

/* APPROACH 1 - recursive */
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        
        
        
            if(!root) return ;
            
             flatten(root->right);
             flatten(root->left);
            
            root->right=prev;
            root->left=NULL;
            prev=root;
    }
};


/* Approach -2 - iterative */

void flatten(TreeNode* root) {
        
        if(!root) return;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr=st.top(); st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            
            if(!st.empty())
            {
                curr->right=st.top();
                curr->left=NULL;
            }
        }
    }
    

 /* Approach -3 - Morris traversal */
 
  void flatten(TreeNode* root) {
        if(!root) return ;
        TreeNode* curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev=curr->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }





/* BST to Doubly linked list */
 
/* recursive approach*/
 void flatten(Node* root,Node* &prev) {
    
    if(!root) return ;
    
    flatten(root->left,prev);
     
    root->left=prev;
    prev->right=root;
    prev=root;
    
    flatten(root->right,prev);
}
    
Node* bToDLL(Node* root)
{
    if(!root) return nullptr;
    Node* prev=NULL;
    Node* dummy = new Node(-1);
    prev=dummy;
    flatten(root,prev);
    Node* head=dummy->right;
    dummy->right=head->left=NULL;
    
    // circular
    
    head->left=prev;
    prev->right=head;
    
    return head;
}


/* iterative approach */



Node* bToDLL(Node* root)
{
    if(!root) return nullptr;
   
    stack<Node*> st;
        add(st,root);
         Node* prev=NULL;
    Node* dummy = new Node(-1);
    prev=dummy;
        while(!st.empty())
        {
            Node* curr=st.top();
            st.pop();
            
            prev->right=curr;
            curr->left=prev;
            prev=curr;
            add(st,curr->right);
        }
        
    Node* head=dummy->right;
    dummy->right=head->left=NULL;
    
    // circular
    
    head->left=prev;
    prev->right=head;
    
    return head;
}



/* Using morris traversal */

Node* getRightMostNode(Node* root,Node* curr)
{
    while(root->right!=NULL and root->right!=curr)
    {
        root=root->right;
    }
    return root;
}

Node* bToDLL(Node* root)
{
    if(!root) return nullptr;
   
    
    
    Node* prev=NULL;
    Node* dummy = new Node(-1);
    prev=dummy; Node* curr=root;
    while(curr)
    {
        Node* lnode=curr->left;
        
        if(lnode==NULL)
        {
            
            // create link
            prev->right=curr;
            curr->left=prev;
            prev=curr;
            
            // move
            curr=curr->right;
        }
        else
        {
            Node* rightMostNode=getRightMostNode(lnode,curr);
            
            if(rightMostNode->right==NULL)
            {
                // thread creation area
                rightMostNode->right=curr;
                curr=curr->left;
            }
            else
            {
                // Break thread
                rightMostNode->right=NULL;
                
                // create link
                prev->right=curr;
                curr->left=prev;
                prev=curr;
                
                // move
                curr=curr->right;
            
            }
        }
        
    }
        
    Node* head=dummy->right;
    dummy->right=head->left=NULL;
    
    // circular
    
    head->left=prev;
    prev->right=head;
    
    return head;
}