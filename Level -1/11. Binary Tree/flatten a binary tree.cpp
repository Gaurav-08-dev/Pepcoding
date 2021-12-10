/**** Perform Reverse Post Order ****/
TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        
        
        
            if(!root) return ;
            
             flatten(root->right);
             flatten(root->left);
            
            root->right=prev;
            root->left=NULL;
            prev=root;
    }


/*** USING STACK ****/
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
    

/**** USNIG MORRIS TRAVERSAL ****/
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